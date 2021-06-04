#!/bin/bash

/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &
dunst &
slstatus &
sxhkd -c ~/.config/sxhkd/sxhkdrc &
nitrogen --set-scaled ~/.wallpaper.jpg &
imwheel -b 45 &
picom -b --experimental-backends  --config ~/.config/picom/picom.conf &


