/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 20;       /* snap pixel */

static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 5;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */

static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */

static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */

static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */

static const char *fonts[]          = { "NotoSansMono Nerd Font:size=11" };
static const char dmenufont[]       = { "NotoSansMono Nerd Font:size=11" };

#include "Schemes/custom.c"


/* tagging */
/* static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" }; */
static const char *tags[] = { "","", "", "﬏", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     		instance  			title           			tags mask  		isfloating  	isterminal  	noswallow  monitor */
	{  "Gimp",    		NULL,     			NULL,           				0,         		1,          	0,          	 0,        	-1 	},
	{  "Firefox", 		NULL,     			NULL,           				1 << 8,    		0,          	0,          	-1,        	-1 	},
	{  "kitty",     	NULL,     			NULL,           				0,         		0,          	1,          	 0,        	-1 	},
	{  "St",     	    NULL,     			NULL,           				0,         		0,          	1,          	 0,        	-1 	},
	{  "st-256color",   NULL,     			NULL,           				0,         		0,          	1,          	 0,        	-1 	},
	{  NULL,      		NULL,     			"Event Tester", 				0,         		0,          	0,          	 1,        	-1 	}, /* xev */
	{ "firefox",		NULL,				NULL,			  				1 << 2,			0,			  	0,				 0,			-1 	},
	{ "qutebrowser",	NULL,				NULL,			  				1 << 2,			0,			  	0,				 0,			-1 	},
	{ "Caprine",	  	"caprine",	    	"Messenger",					1 << 5,			0,			  	0,				 0,			-1 	},
	{ "whatsapp-nativefier-d40211",	NULL,	NULL,							1 << 3,			0,				0,			  	 0,			-1 	},
	{ "zoom",			NULL,			 	"Settings",		  				1 << 3,			1,				0,	 			 0,			-1 	},
	{ "zoom",		   	"zoom",			 	NULL,		  	  				1 << 3,			1,				0,	 			 0,			-1 	},
	{ "firefox",	  	"Toolkit",			"Picture-in-Picture", 	  		1 << 2,			1,				0,	 			 0,			-1 	},
	{ "Subl3",		   	"subl3", 			NULL,			  				1 << 4,			0,				0,	 			 0,			-1	},
	{ "Code",		   	"code", 			NULL,			  				1 << 4,			0,				0,	 			 0,			-1	},
	{ "xdman-Main",	 	NULL, 				NULL,			  				0,		    	1,				0,	 			 0,			-1	},


};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

#include "patch/shiftview.c"
#include "patch/movestack.c"


static const Layout layouts[] = {
	/* symbol     			arrange function */
	{ 	"﬿",       			tile 					},    /* first entry is default */
	{ 	"",       			NULL 					},    /* no layout function means floating behavior */
	{ 	"",       			spiral 					},
	{ 	"",       			dwindle 				},
	{ 	"H[]",       			deck 					},
	{ 	"ﰧ",       			bstack 					},
	{ 	"",     			bstackhoriz 			},
	{ 	"﩯",       			grid 					},
	{ 	"﩯",      			gaplessgrid 			},
	{ 	"﩯",      			nrowgrid 				},
	{ 	"﩯",      			horizgrid 				},
	{ 	"頻",      			centeredmaster 			},
	{ 	"恵",      			centeredfloatingmaster 	},
	{ 	"[M]",      			monocle 				},
	{ 	NULL,       			NULL 					}
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
static const char *dmenucmd[] = { "dmenu_run" };
static const char *termcmd[]  = { "st", NULL };

static Key keys[] = {
	/* modifier                     key        		function        argument */

	/* ================================= B A S I C ====================================== */
	{ MODKEY,                       XK_p,      		spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, 		spawn,          {.v = termcmd } },
	{ MODKEY,		                XK_q,      		killclient,     {0} },

	{ MODKEY,                       XK_b,      		togglebar,      {0} },

	{ MODKEY,                       XK_j,      		focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      		focusstack,     {.i = -1 } },

	{ MODKEY,                       XK_i,      		incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      		incnmaster,     {.i = -1 } },

	{ MODKEY,                       XK_h,      		setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      		setmfact,       {.f = +0.05} },
/*	{ MODKEY,                       XK_Return, 		zoom,           {0} }, */

	/* ============================= V A N I T Y G A P S ================================= */
	{ MODKEY,          		    	XK_0,      		togglegaps,     {0} },
	{ MODKEY|ShiftMask,		    	XK_0,      		defaultgaps,    {0} },

	{ MODKEY,          			    XK_equal,      	incrgaps,       {.i = +1 } },
	{ MODKEY,					    XK_minus,      	incrgaps,       {.i = -1 } },

	{ MODKEY,		              	XK_i,      		incrigaps,      {.i = +1 } },
	{ MODKEY|ShiftMask,    			XK_i,      		incrigaps,      {.i = -1 } },

	{ MODKEY,              			XK_o,      		incrogaps,      {.i = +1 } },
	{ MODKEY|ShiftMask,    			XK_o,      		incrogaps,      {.i = -1 } },

	{ MODKEY,          		    	XK_6,      		incrihgaps,     {.i = +1 } },
	{ MODKEY|ShiftMask,		    	XK_6,      		incrihgaps,     {.i = -1 } },

	{ MODKEY,              			XK_7,      		incrivgaps,     {.i = +1 } },
	{ MODKEY|ShiftMask,    			XK_7,      		incrivgaps,     {.i = -1 } },

	{ MODKEY,          		    	XK_8,      		incrohgaps,     {.i = +1 } },
	{ MODKEY|ShiftMask,		    	XK_8,      		incrohgaps,     {.i = -1 } },

	{ MODKEY,              			XK_9,      		incrovgaps,     {.i = +1 } },
	{ MODKEY|ShiftMask,    			XK_9,      		incrovgaps,     {.i = -1 } },

	/* ============================== M O V E S T A C K ================================= */
	{ MODKEY|ShiftMask,             XK_j,      		movestack,      {.i = +1 } },
 	{ MODKEY|ShiftMask,             XK_k,      		movestack,      {.i = -1 } },

	{ MODKEY,                       XK_Tab,    		view,           {0} },

	/* =============================== L A Y O U T S ==================================== */
	{ MODKEY|Mod1Mask,				XK_t,      		setlayout,      {.v = &layouts[0]} }, 	/* Tile */
	{ MODKEY|Mod1Mask,				XK_f,      		setlayout,      {.v = &layouts[1]} }, 	/* Floating */

	{ MODKEY|Mod1Mask,				XK_s,      		setlayout,      {.v = &layouts[2]} }, 	/* Spiral */
	{ MODKEY|Mod1Mask|ShiftMask,	XK_s,      		setlayout,      {.v = &layouts[3]} }, 	/* Dwindle */

	{ MODKEY|Mod1Mask,				XK_d,      		setlayout,      {.v = &layouts[4]} }, 	/* Deck */

	{ MODKEY|Mod1Mask,				XK_b,      		setlayout,      {.v = &layouts[5]} }, 	/* Bottomstack */
	{ MODKEY|Mod1Mask|ShiftMask,	XK_b,      		setlayout,      {.v = &layouts[6]} }, 	/* Bottomstack Horizontal */

	{ MODKEY|Mod1Mask,				XK_g,      		setlayout,      {.v = &layouts[7]} }, 	/* Gird */
	{ MODKEY|Mod1Mask|ShiftMask,	XK_g,      		setlayout,      {.v = &layouts[8]} },	/* Gird Gapless*/
	{ MODKEY|Mod1Mask,				XK_n,      		setlayout,      {.v = &layouts[9]} }, 	/* Gird Row */
	{ MODKEY|Mod1Mask,				XK_h,      		setlayout,      {.v = &layouts[10]} }, 	/* Gird Horizontal */

	{ MODKEY|Mod1Mask,				XK_m,      		setlayout,      {.v = &layouts[11]} },	/* Centeredmaster */
	{ MODKEY|Mod1Mask|ShiftMask,	XK_m,      		setlayout,      {.v = &layouts[12]} },	/* Centeredmaster Floating */

	{ MODKEY|ControlMask,			XK_m,      		setlayout,      {.v = &layouts[13]} },	/* Monocole */

	{ MODKEY,						XK_space,  		togglefloating, {0}                 },
    { MODKEY,                       XK_s,           togglesticky,   {0}                 },
	/* { MODKEY,                       XK_space,  setlayout,      {0} }, */



	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_a,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_a,      tag,            {.ui = ~0 } },

	{ MODKEY|Mod1Mask,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY|Mod1Mask,                       XK_period, focusmon,       {.i = +1 } },

	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	{ MODKEY,                       XK_comma,  		shiftview,      {.i = -1 } },
	{ MODKEY,                       XK_period, 		shiftview,      {.i = +1 } },

    { MODKEY|ControlMask,           XK_space,  focusmaster,    {0} },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[5]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	// { ClkClientWin,         MODKEY|ShiftMask, Button1,      swalmouse,      {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

