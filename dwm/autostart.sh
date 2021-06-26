#!/bin/bash

function run {
 if ! pgrep $1 ;
  then
    $@&
  fi
}

run "nm-applet"
run "blueberry-tray"
run "numlockx on"
run "volumeicon"
run slstatus &
run "/usr/lib/xfce4/notifyd/xfce4-notifyd"
run "/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1"

# /usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &
ibus-daemon -drxR &
# dunst &
# slstatus &
sxhkd -c ~/.config/sxhkd/sxhkdrc &
nitrogen --set-scaled ~/.wallpaper.jpg &
imwheel -b 45 &
picom -b --experimental-backends  --config ~/.config/picom/picom.conf &


