/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>
/* appearance */
static const unsigned int borderpx = 0; /* border pixel of windows */
static const unsigned int snap = 32;    /* snap pixel */
static const int showbar = 1;           /* 0 means no bar */
static const int topbar = 1;            /* 0 means bottom bar */
static const char *fonts[] = {"monospace:size=13", "JetBrains Mono:size=12"};
static const char dmenufont[] = "Jetbrains Mono:size=11";
static const char col_gray1[] = "#000000";
static const char col_gray2[] = "#000000";
static const char col_gray3[] = "#1bf53c";
static const char col_gray4[] = "#eeeeee";
static const char col_cyan[] = "#2af7f3";
static const char *colorsdark[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
    [SchemeSel] = {col_gray4, col_cyan, col_cyan},
};

static const char *colorslight[][3] = {
    [SchemeNorm] = {col_gray1, col_gray3, col_gray2},
    [SchemeSel] = {col_cyan, col_gray4, col_cyan},

};

/* tagging */
static const char *tags[] = {"\uf120", "\uf372", "\ueb26", "\uf02d", "\ueb51"};

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    {"Gimp", NULL, NULL, 0, 1, -1},
    {"Firefox", NULL, NULL, 1 << 8, 0, -1},
};

/* layout(s) */
static const float mfact = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"><>", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle},
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

/* commands */
static char dmenumon[2] = "0";
static const char *dmenudark[] = {"dmenu_run", "-m",      dmenumon, "-i",
                                  "-fn",       dmenufont, "-nb",    col_gray1,
                                  "-nf",       col_gray3, "-sb",    col_cyan,
                                  "-sf",       col_gray4, NULL};
static const char *dmenulight[] = {"dmenu_run", "-m",      dmenumon, "-i",
                                   "-fn",       dmenufont, "-nb",    col_gray3,
                                   "-nf",       col_gray1, "-sb",    col_cyan,
                                   "-sf",       col_gray4, NULL};

static const char *termcmd[] = {"st", NULL};
static const char *upbrightness[] = {"xbacklight", "-inc", "10", NULL};
static const char *downbrightness[] = {"xbacklight", "-dec", "10", NULL};

static const Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY, XK_p, spawndmenu, {0}},
    {MODKEY | ShiftMask, XK_Return, spawn, {.v = termcmd}},
    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY, XK_d, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY, XK_Return, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY | ShiftMask, XK_c, killclient, {0}},
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY | ShiftMask, XK_space, togglealwaysontop, {0}},
    {0, XK_Print, spawn, SHCMD("flameshot gui")},
    {0, XK_F1, view, {.ui = 1}},
    {MODKEY, XK_F1, tag, {.ui = 1 << 0}},
    {0, XK_F2, view, {.ui = 2}},
    {MODKEY, XK_F2, tag, {.ui = 2 << 0}},
    {0, XK_F3, view, {.ui = 4}},
    {MODKEY, XK_F3, tag, {.ui = 4 << 0}},
    {0, XK_F4, view, {.ui = 8}},
    {MODKEY, XK_F4, tag, {.ui = 8 << 0}},
    {0, XK_F5, view, {.ui = 16}},
    {MODKEY, XK_F5, tag, {.ui = 16 << 0}},
    {0, XK_F6, view, {.ui = 32}},
    {MODKEY, XK_F6, tag, {.ui = 32 << 0}},
    {0, XK_F7, view, {.ui = 64}},
    {MODKEY, XK_F7, tag, {.ui = 64 << 0}},
    {0, XK_F8, view, {.ui = 128}},
    {MODKEY, XK_F8, tag, {.ui = 128 << 0}},
    {0, XK_F9, view, {.ui = 256}},
    {MODKEY, XK_F9, tag, {.ui = 256 << 0}},
    {0, XK_F10, view, {.ui = ~0}},
    {MODKEY, XK_F10, tag, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_q, quit, {0}},
    {0, XF86XK_MonBrightnessUp, spawn, {.v = upbrightness}},
    {0, XF86XK_MonBrightnessDown, spawn, {.v = downbrightness}},
    // Increase volume
    {MODKEY, XF86XK_AudioRaiseVolume, spawn,
     SHCMD("amixer set Master 5%+ unmute")},
    // Decrease volume
    {MODKEY, XF86XK_AudioLowerVolume, spawn,
     SHCMD("amixer set Master 5%- unmute")},
    // Mute/Unmute toggle
    {MODKEY, XF86XK_AudioMute, spawn, SHCMD("amixer set Master toggle")},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
