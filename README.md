# elh-dwm
My DWM Build
Compiled on Void Linux

# Build Dependencies
- libXinerama-devel
- libXft-devel
- freetype-devel

# Optional
By default, I am using ST, rofi, spectacle, and nemo.  If you do not wish to use any of these, you can edit config.def.h to replace st with a terminal of your choice, rofi with dmenu, etc.

I have some catches built in to find alternatives.

**Example:**

- If you don't have rofi, it will default to dmenu
- If you don't have firefox, it will try chromium, then librewolf.
- nemo is by default.

# Patches
By default, I have systray, uselessgaps, and autostart as my patches. It has already been patched so no further action is needed.

If you choose to remove any of these patches. Install *patch* from your distro's package manager and remove them using this sytax

1. `patch p1 < patch-name.diff`
2.  correct any errors that may happen
3. `sudo make clean install`

# Starting it from a Display Manager (SDDM, LightDM, etc;)
Create a .desktop file in /usr/share/xsession

[Desktop Entry]

Name=dwm

Comment=Dynamic Window Manager  

Exec=dwm

Type=Application
