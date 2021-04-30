/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 3;        /* gaps between windows */
static const unsigned int snap      = 12;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 0;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "NotoSansMono Nerd Font:size=10"  };
static const char dmenufont[]       = "NotoSansMono Nerd Font:size=10";

#include "Schemes/koi.c"

static const unsigned int baralpha = 255;
static const unsigned int borderalpha = 100;
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};


/* tagging */
/* static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" }; */
static const char *tags[] = { "","", "", "", "﬏", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *  use tags mask to point an application to a specific workspace
	 */
	/* class													instance							 title									tags mask	  isfloating	monitor */
	{ "Gimp",														NULL,									NULL,											0,					0,			  -1 	},
	{ "Xfce4-terminal",									NULL,									NULL,											0,					1,			  -1 	},
	{ "firefox",												NULL,									NULL,			  						1 << 2,				0,			  -1 	},
	{ "qutebrowser",										NULL,									NULL,			  						1 << 2,				0,			  -1 	},
	{ "Caprine",											"caprine",	    		 "Messenger",		  					1 << 3,				1,			  -1 	},
	{ "discord",				  							NULL,	    						NULL,		  	  					1 << 3,				0,			  -1 	},
	{ "Spotify",					  					"spotify",	   	   "Spotify Free",		  				1 << 3,				0,			  -1 	},
	{ "whatsapp-nativefier-d40211",			NULL,	     						NULL,		  	  					1 << 3,				0,			  -1 	},
	{ "Arcolinux-welcome-app.py",				NULL,									NULL,			    						0,					1,			  -1 	},
	{ "zoom",														NULL,			 				 "Settings",		  					1 << 3,				1,			  -1 	},
	{ "zoom",							   					 "zoom",			 	        NULL,		  	  					1 << 3,				1,			  -1 	},
	{ "firefox",						  			  "Toolkit",			 "Picture-in-Picture", 					1 << 2,				1,			  -1 	},
	{ "mpv",														"gl",									NULL,											1,					0,			  -1	},
	{ "Subl3",							   				 "subl3", 							NULL,			  						1 << 4,				0,			  -1	},
	{ "Code",							   					 "code", 								NULL,			  						1 << 4,				0,			  -1	},
	{ "Thunar",							  					NULL, 								NULL,			  						1 << 5,				0,			  -1	},
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#include "Layouts/fibonacci.c"
#include "Layouts/grid.c"
#include "Layouts/tcl.c"
#include "Layouts/column.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ " ﬿",      tile },    /* first entry is default */
	{ " ",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ " 﩯",     grid },
	{ " 𤋮",     tcl },
	{ " ",	  spiral },
	{ " ",	  dwindle },
	{ "侀",      bstack },
	{ "",      bstackhoriz },
 	{ "|||",      col },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", norm_fg, "-nf", norm_bg, "-sb", sel_bg, "-sf", sel_fg, NULL };
static const char *filecmd[]  = { "thunar", NULL };
static const char *calendar[] = { "gsimplecal", NULL };
static const char *bashtop[]  = { "xfce4-taskmanager", NULL };

#include "selfrestart.c"
#include "shiftview.c"
#include "movestack.c"

static Key keys[] = {
	/* modifier                     key        		function        argument */
	{ MODKEY,                       XK_p,      		spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_r,      		self_restart,   {0} },
	{ MODKEY,                       XK_b,      		togglebar,      {0} },
	{ MODKEY,				 				        XK_space,  		togglefloating, {0} },

	{ MODKEY,                       XK_j,      		focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      		focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_Right,  		focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_Left,   		focusstack,     {.i = -1 } },
	{ MODKEY|ControlMask,           XK_space,  		focusmaster,    {0} },

	{ MODKEY|ShiftMask,             XK_j,      		movestack,     	{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      		movestack,     	{.i = -1 } },

	{ MODKEY,                       XK_i,      		incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      		incnmaster,     {.i = -1 } },

	{ MODKEY,                       XK_h,      		setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      		setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_minus,  		setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  		setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  		setgaps,        {.i = 0  } },

	/*{ MODKEY,                     XK_Return, 		zoom,           {0} },*/
	{ MODKEY,            			XK_q,			killclient,     {0} },

	{ MODKEY,                       XK_Tab,    		view,           {0} },
	{ MODKEY,                       XK_0,      		view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      		tag,            {.ui = ~0 } },

	{ MODKEY|ControlMask,           XK_t,      		setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ControlMask,           XK_f,      		setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ControlMask,           XK_g,      		setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ControlMask,           XK_m,      		setlayout,      {.v = &layouts[4]} },
	{ MODKEY|ControlMask,           XK_s,      		setlayout,      {.v = &layouts[5]} },
	{ MODKEY|ShiftMask,             XK_f,      		setlayout,      {.v = &layouts[6]} },
	{ Mod1Mask,		 	            XK_b,      		setlayout,      {.v = &layouts[7]} },
	{ Mod1Mask|ShiftMask,           XK_b,      		setlayout,      {.v = &layouts[8]} },
	{ MODKEY,                       XK_c,      		setlayout,      {.v = &layouts[9]} },
	/*{ ControlMask,	                XK_space,  		setlayout,      {3} },*/

	{ Mod1Mask,                     XK_comma,  		focusmon,       {.i = -1 } },
	{ Mod1Mask,                     XK_period, 		focusmon,       {.i = +1 } },

	{ MODKEY,                       XK_comma,  		shiftview,      {.i = -1 } },
	{ MODKEY,                       XK_period, 		shiftview,      {.i = +1 } },

	{ MODKEY|ShiftMask,             XK_comma,  		tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, 		tagmon,         {.i = +1 } },

/*  { MODKEY|ShiftMask,		        XK_space,  		shiftview,	   { .i = 1 } }, */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* IF YOU HAVE A AZERTY KEYBOARD USE THESE CODES
	TAGKEYS(                        XK_ampersand,              0)
	TAGKEYS(                        XK_eacute,                 1)
	TAGKEYS(                        XK_quotedbl,               2)
	TAGKEYS(                        XK_apostrophe,             3)
	TAGKEYS(                        XK_parenleft,              4)
	TAGKEYS(                        XK_section,                5)
	TAGKEYS(                        XK_egrave,                 6)
	TAGKEYS(                        XK_exclam,                 7)
	TAGKEYS(                        XK_ccedilla,               8)
*/

/* THESE ARE THE ORIGINAL QWERTY KEYBOARD CODES
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
*/

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        spawn,          {.v = bashtop } },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = filecmd } },
	{ ClkStatusText,        0,              Button3,        spawn,          {.v = calendar } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
