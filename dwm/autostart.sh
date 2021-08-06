#!/bin/bash

function run {
 if ! pgrep $1 ;
  then
    $@&
  fi
}

# run "xrandr --output DP2 --right-of eDP1 --auto"
run "numlockx on"
run "volumeicon"
run "nm-applet"
# run "blueberry-tray"
run slstatus &
run "/usr/lib/xfce4/notifyd/xfce4-notifyd"
run "/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1"

# ibus-daemon -drxR &
# dunst &
sxhkd -c ~/.config/sxhkd/sxhkdrc &
nitrogen --restore &
imwheel -b 45 &
picom -b --experimental-backends  --config ~/.config/picom/picom.conf &


