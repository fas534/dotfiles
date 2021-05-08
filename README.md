# dotfiles

dwm - dynamic window manager
============================
dwm is an extremely fast, small, and dynamic window manager for X.

Layouts
-------
Source has been patched to support a number of layouts.

	- Tile
	- Float
	- Monocole
	- Grid
	- 3 column
	- Fibonacci (Sprial + Dwindle)
	- Bottomstack

Icons
-----
Nerd Font is used for statusbar icons for better avaiability of icons.


slstatus - suckless status
==========================
slstatus is a suckless status monitor for window managers that use WM_NAME
(e.g. dwm) or stdin to fill the status bar.

Volume info fix
---------------
slstatus often does not show volumn info due to missing amixer file.
Create a new file name named "modules.conf" in /etc/modules-load.d/ & add this line in the file-

	snd-pcm-oss

Then reboot.
