# XDG PATH
export XDG_DATA_HOME=${XDG_DATA_HOME:="$HOME/.local/share"}
export XDG_CONFIG_HOME=${XDG_CONFIG_HOME:="$HOME/.config"}

# iBus
export GTK_IM_MODULE=ibus
export XMODFIERS=@im=ibus
export QT_IM_MODULE=ibus

export EDITOR='nvim'
export TERMINAL="kitty"
export READER="zathura"
export MANPAGER="sh -c 'col -bx | bat -l man -p'"

# YTFZF
export YTFZF_HIST=0
export YTFZF_LOOP=0

# STARSHIP
# export STARSHIP_CONFIG=~/.config/starship/config.toml

