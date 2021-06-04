static const char norm_fg[] = "#D3D3D3"; // Text
//static const char norm_bg[] = "#0F161E";
static const char norm_bg[] = "#282828";
static const char norm_border[] = "#E67E80"; // Slave Bordere

static const char sel_fg[] = "#282828";
static const char sel_bg[] = "#D3D3D3"; // Topbar
static const char sel_border[] = "#D3C6AA"; // Master Border

static const char urg_fg[] = "#a4c098";
static const char urg_bg[] = "#282828";
static const char urg_border[] = "#282828";

static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
};

// dmenu_run -m -fn 'NotoSansMono Nerd Font' -nb '#0F161E' -nf '#a4c098' -sb '#a4c098' -sf '#282828'
