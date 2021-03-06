/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 1; /* border pixel of windows */

static const unsigned int gappx = 25; /* gaps between windows */
static const unsigned int snap = 32;  /* snap pixel */
static const unsigned int systraypinning =
    0; /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor
          X */
static const unsigned int systrayonleft =
    0; /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 1; /* systray spacing */
static const int systraypinningfailfirst =
    1; /* 1: if pinning fails, display systray on the first monitor, False:
          display systray on the last monitor*/
static const int showsystray = 1;  /* 0 means no systray */
static const int showbar = 1;      /* 0 means no standard bar */
static const int topbar = 1;       /* 0 means standard bar at bottom */
static const int extrabar = 0;     /* 0 means no extra bar */
static const char statussep = ';'; /* separator between statuses */
static const char *fonts[] = {"Source Code Pro:size=15", "FontAwesome:size=15"};
static const char dmenufont[] = "monospace:size=15";
static const char col_gray1[] = "#1a1826"; /* Workspace Empty Space */
static const char col_gray2[] = "#000000"; /* No Clue */
static const char col_gray3[] = "#F28fad"; /* Inactive Workspace Color */
static const char col_gray4[] = "#d9e0ee"; /* X Window Text */
static const char col_cyan[] = "#302d41";  /* Active Color Bar  */

static char normbgcolor[] = "#2E3440";
static char normbordercolor[] = "#3B4252";
static char normfgcolor[] = "#ECEFF4";
static char selfgcolor[] = "#D8DEE9";
static char selbordercolor[] = "#5E81AC";
static char selbgcolor[] = "#191c23";

static char *colors[][3] = {
    /*               fg           bg           border   */
    [SchemeNorm] = {normfgcolor, normbgcolor, normbordercolor},
    [SchemeSel] = {selfgcolor, selbgcolor, selbordercolor},
};

/* tagging */
static const char *tags[] = {"???", "???", "???", "???", "???", "???", "???", "???", "???"};

static const char *tagsel[][2] = {
    {"#ff0000", "#302d41"}, {"#ff7f00", "#302d41"}, {"#ffff00", "#302d41"},
    {"#00ff00", "#302d41"}, {"#0000ff", "#302d41"}, {"#4b0082", "#302d41"},
    {"#9400d3", "#302d41"}, {"#ffffff", "#302d41"}, {"#000000", "#302d41"},
};

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    {"Gimp", NULL, NULL, 0, 1, -1},
    {"Firefox", NULL, NULL, 1 << 8, 0, -1},
    {"feh", NULL, NULL, 0, -1, 0},
};

/* layout(s) */
static const float mfact = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    0; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */

#include "fibonacci.c"
static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[T]", tile}, /* first entry is default */
    {"[N]", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle}, {"[S]", spiral}, {"[D]", dwindle},
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
#include <X11/XF86keysym.h>
/* commands */
static char dmenumon[2] =
    "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
    "dmenu_run", "-m",      dmenumon, "-fn",    dmenufont, "-nb",     col_gray1,
    "-nf",       col_gray3, "-sb",    col_cyan, "-sf",     col_gray4, NULL};
static const char *termcmd[] = {"st", NULL};
static const char *upvol[] = {"/usr/bin/pactl", "set-sink-volume", "0", "+5%",
                              NULL};
static const char *downvol[] = {"/usr/bin/pactl", "set-sink-volume", "0", "-5%",
                                NULL};
static const char *mutevol[] = {"/usr/bin/pactl", "set-sink-mute", "0",
                                "toggle", NULL};

static Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY, XK_d, spawn, SHCMD("rofi -show drun || dmenu_run")},
    {MODKEY, XK_Return, spawn, SHCMD("tabbed -r 2 st -w '' || st ")},
    {MODKEY | ShiftMask, XK_b, togglebar, {0}},
    {MODKEY | ControlMask, XK_b, toggleextrabar, {0}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY, XK_o, incnmaster, {.i = -1}},
    {MODKEY, XK_p, spawn, SHCMD("pcmanfm")},
    {MODKEY, XK_b, spawn, SHCMD("librewolf || firefox || chromium")},
    {MODKEY, XK_x, spawn, SHCMD("slock")},
    {0, XK_Print, spawn,
     SHCMD("flameshot gui --path $HOME/Pictures/screenshots/")},
    {ShiftMask, XK_Print, spawn,
     SHCMD("mkdir ~/Pictures/screenshots & pkill feh & scrot "
           "'screenshot_%Y%m%d_%H%M%S.png' -e 'xclip -selection clip -t "
           "image/png \"$f\" && feh \"$f\" && mv \"$f\" "
           "~/Pictures/screenshots/ || mv \"$f\" ~/Pictures/screenshots/'")},
    {0, XF86XK_AudioLowerVolume, spawn, {.v = downvol}},
    {0, XF86XK_AudioMute, spawn, {.v = mutevol}},
    {0, XF86XK_AudioRaiseVolume, spawn, {.v = upvol}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY | ShiftMask, XK_Return, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY | ShiftMask, XK_q, killclient, {0}},
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY | ShiftMask, XK_f, togglefullscr, {0}},
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ControlMask | ShiftMask, XK_q, quit, {1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = -1}},
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8){MODKEY | ShiftMask, XK_r, quit, {0}},
    {MODKEY, XK_e, setlayout, {.v = &layouts[3]}},
    {MODKEY | ShiftMask, XK_e, setlayout, {.v = &layouts[4]}},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function argument
     */
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkExBarLeftStatus, 0, Button2, spawn, {.v = termcmd}},
    {ClkExBarMiddle, 0, Button2, spawn, {.v = termcmd}},
    {ClkExBarRightStatus, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
