# elh-dwm
My DWM Build
Compiled on Void Linux

# Build Dependencies
- libXinerama-devel
- libXft-devel
- freetype-devel
- All dependencies that are included with the previously stated

# Optional
By default, I am using ST, rofi, scrot, and nemo.  If you do not wish to use any of these, you can edit config.def.h to replace st with a terminal of your choice, rofi with dmenu, etc.

I have some catches built in to find alternatives.

**Example:**

- rofi -> dmenu
- firefox -> chromium -> librewolf -> brave
- nemo -> ranger (via st) -> thunar -> dolphin -> nautilus

# Patches
By default, I have systray, uselessgaps, and autostart as my patches. It has already been patched so no further action is needed.

If you choose to remove any of these patches. Install *patch* from your distro's package manager and remove them using this sytax

1. `patch p1 < patch-name.diff`
2.  correct any errors that may happen
3. `sudo make clean install`

# Starting it from a Display Manager (SDDM, LightDM, etc;)
Create a .desktop file in /usr/share/xsessions/

[Desktop Entry]

Name=dwm

Comment=Dynamic Window Manager  

Exec=dwm

Type=Application

# Hotkeys

For the most part, I am using default DWM hotkeys, with some odd exceptions
1. The Mod key is Super/Windows/Command Key.
2. Mod + P opens File Manager
3. Mod + D opens dmenu/rofi
4. Printscreen allows OSX Style Screenshot via Scot
5. Shift + Printscreen takes a screenshot of entire screen(s) 
6. Mod + Shift + Q closes focused application
7. Mod + Shift + R quits dwm

