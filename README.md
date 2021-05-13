# dotfiles

## Details

**Distro:** [Arcolinux](https://arcolinux.com)

**WM:** [dwm](https://dwm.suckless.org/)

**Shell:** [zsh](https://github.com/zsh-users/zsh)

**Terminal:** [kitty](https://sw.kovidgoyal.net/kitty/)

**Colorscheme:** A slightly modified version of [gruvbox](https://github.com/morhetz/gruvbox).

> My build is heavily inspired by [b4skyx's](https://github.com/b4skyx) build. Saying inspired is probably wrong & unethical, I'm using his colorscheme [serenade](https://github.com/b4skyx/serenade) in my editors. 

---

## dwm - Dynamic Window Manager
 =========================================

dwm is an extremely fast, small, and dynamic window manager for X.

### Patches
[Arcolinux dwm](https://www.arcolinuxd.com/category/dwm/) comes with a handful of patches. I patched my dwm build to the point where you can consider it as a bloated build of dwm. **My soul embraced the bloat <3**.

This build supports colored emojis.

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

### Fonts & Icons

Unlike others, I believe in [**Nerd Fonts**](https://www.nerdfonts.com/)'s supremacy for statusbar icons.

[**Cascadia Code**](https://github.com/microsoft/cascadia-code) is used in terminal.

### Status Monitor

I'm using [slstatus](https://github.com/drkhsh/slstatus) as my status monitor.

---

## slstatus - Suckless Status
==============================

slstatus is a suckless status monitor for window managers that use WM_NAME
(e.g. dwm) or stdin to fill the status bar.

### "Volume info showing n/a" fix

slstatus often does not show volumn info due to missing `amixer` file.

To fix this
```bash
echo "snd-pcm-oss" > modules.conf
sudo mv modules.conf /etc/modules-load.d/
```
Then reboot.



## Miscellaneous
==================

Applications can be automatically started on startup by adding them into .xinitrc instead of using dwm's autostart patch. Be sure to configure the `autostart.sh` according to your source directory.

---

## Neovim
==========

Using [b4skyx](https://github.com/b4skyx)'s [configuration](https://github.com/b4skyx/dotfiles/tree/master/.config/nvim). Configured it to use for C programming-
- clang
- nodejs
- nvim-coc
- nvim-coc-clangd-git

---



## Wallpapers
- ### koi 
![koi](wallpapers/koi.jpg)

