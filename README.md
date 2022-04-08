# elh-dwm
My DWM Build

Tested and working Distros
-------
1. Void Linux
2. Alpine Linux
3. Rocky Linux/Fedora
4. MXLinux/Debian

Complimentaries
-------
Relies on (Not required)
1. [elh-st](https://github.com/elliehelisky/elh-st)
2. [elh-slock](https://github.com/elliehelisky/elh-slock)
3. [elh-tabbed](https://github.com/elliehelisky/elh-tabbed)

Build Dependencies
-------
- libXinerama-devel
- libXft-devel
- freetype-devel
- All dependencies that are included with the previously stated

Optional
-------
By default, I am using ST, rofi, spectacle, and nemo.  If you do not wish to use any of these, you can edit config.def.h to replace st with a terminal of your choice, rofi with dmenu, etc.

I have some catches built in to find alternatives.

**Example:**

- rofi -> dmenu
- firefox -> chromium -> librewolf -> brave
- nemo -> ranger (via st) -> thunar -> dolphin -> nautilus

Patches
-------
All patches that I used are included in this repository

If you choose to remove any of these patches. Install *patch* from your distro's package manager and remove them using this sytax

1. `patch p1 < patch-name.diff`
2.  correct any errors that may happen
3. `sudo make clean install`

Starting it from a Display Manager (SDDM, LightDM, etc;)
-------
Create a .desktop file in /usr/share/xsessions/

[Desktop Entry]

Name=dwm

Comment=Dynamic Window Manager  

Exec=dwm

Type=Application

Hotkeys
-------
For the most part, I am using default DWM hotkeys, with some odd exceptions
1. The Mod key is Super/Windows/Command Key.
2. Mod + P opens File Manager
3. Mod + D opens dmenu/rofi
4. Printscreen opens Spectacle/Flameshot
5. Mod + Shift + Q closes focused application
6. Mod + Shift + R quits dwm
7. Mod + X will lock the screen using slock
8. Mod + E / Mod + Shift + E will change the layout from spiral/dwindle
9. Mod + Ctrl + Shift + q will restart dwm without logging out
