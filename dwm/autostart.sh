#!/bin/bash

function run {
 if ! pgrep $1 ;
  then
    $@&
  fi
}
run "dex $HOME/.config/autostart/arcolinux-welcome-app.desktop"
#xrandr -s 1920x1080 &

#run "nm-applet"
#run "pamac-tray"
#run "variety"
#run "xfce4-power-manager"
#run "blueberry-tray"
run "/usr/lib/xfce4/notifyd/xfce4-notifyd"
run "/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1"
picom -b --experimental-backends  --config ~/.config/picom/picom.conf &
run "numlockx on"
#run "volumeicon"
run slstatus &
sxhkd -c ~/.config/sxhkd/sxhkdrc &
nitrogen --set-scaled ~/.wallpaper.jpg &
imwheel -b 45

#run "insync start"
#run "spotify"
#run "ckb-next -b"
#run "discord"
#run "telegram-desktop"

