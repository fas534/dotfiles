# dotfiles

## dwm - dynamic window manager
 =========================================

dwm is an extremely fast, small, and dynamic window manager for X.


### Layouts

Source has been patched to support a number of layouts.

1. Tile
2. Float
3. Monocole
4. Gapless Grid
5. 3 column
6. Fibonacci (Sprial)
7. Fibonacci (Dwindle)
8. Bottomstack

### Icons

[**Nerd Fonts**](https://www.nerdfonts.com/) is used for statusbar icons for it's better looks & rich library of icons.

[**Cascadia Code**](https://github.com/microsoft/cascadia-code) is used for termial. It supports a wide variety of ligatures.

---
## slstatus - suckless status
==============================

slstatus is a suckless status monitor for window managers that use WM_NAME
(e.g. dwm) or stdin to fill the status bar.

### "Volume info showing n/a" fix

slstatus often does not show volumn info due to missing amixer file.

To fix this
```bash
echo "snd-pcm-oss" > modules.conf
sudo mv modules.conf /etc/modules-load.d/
```
Then reboot.

## nvim
To use nvim for C programming, Install-
- clang
- nodejs
- nvim-coc
- nvim-coc-clangd-git

## misc
Autostart applications can be started at startup by adding them into .xinitrc.

## wallpapers
- koi 
![koi](wallpapers/koi.jpg)

