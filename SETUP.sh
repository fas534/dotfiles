#!/bin/sh

# # Update system
echo ">>> UPDATING SYSTEM <<<"
sudo pacman -Syu --noconfirm --needed
echo ">>> SYSTEM UPGRADED <<<"


# Install paru
echo ""
echo ">>> Installing paru-bin <<<"
sudo pacman -S -noconfirm --needed paru-bin

# # Install Terminal Applications
echo ""
echo ">>> INSTALLING TERMINAL APPLICATIONS <<<"
sudo paru -S --noconfirm --needed kitty axel auto-cpufreq bat cmus ranger fzf neovim nitrogen rofi rsync speedtest-cli sxhkd sxiv tldr ytfzf zathura zathura-cb zathura-djvu zathura-pdf-mupdf lsd ueberzug slurm

# Install GUI applications
echo ""
echo ">>> INSTALLING GUI APPLICATIONS <<<"
sudo paru -S --noconfirm --needed firefox mpv obs-studio onlyoffice-bin  qbittorrent qutebrowser visual-studio-code-bin zoom sublime-text-4

# Install Fonts & Icons
echo ""
echo ">>> INSTALLING FONTS & ICONS <<<"
sudo paru -S --noconfirm --needed ttf-font-awesome ttf-hack noto-fonts otf-cascadia-code papirus-icon-theme terminus-font

# Neovim setup
echo ""
echo ">>> SETTING UP NEOVIM <<<"
sudo paru -S --noconfirm --needed clang nodejs

# Installing AUR packages
echo ""
echo ">>> INSTALLING AUR PACKAGES <<<"
paru -S --noconfirm --needed colorpicker ibus-avro-git ms-office-online-nativefier neovim-coc neovim-coc-clangd-git nerd-fonts-noto-sans-mono picom-ibhagwan-git ytfzf

# Copying configs
echo ">>> COPYING CONFIGS TO ./config <<<"
rsync -vP .Xresources ~/
rsync -vP zsh/* ~/
rsync -dvrP kitty dwm cava picom rofi slstatus ytfzf zathura ranger nvim sxhkd ~/.config/

