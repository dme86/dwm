# dwm - dynamic window manager

dwm is an extremely fast, small, and dynamic window manager for X.

## install

### arch

`pacman -S base-devel git libx11 libxft xorg-server xorg-xinit libxinerama neovim ttf-meslo-nerd alacrtity pacman-contrib terminus-font`
`git clone https://github.com/dme86/dwm.git`

`echo "exec dwm" > ~/.xinitrc`



build dwm:
`cd dwm/`
`make install`

build dwmblocks
`cd dwm/dwmblocks-async`
`make dwmblocks`
`make install`

## Keybindings

Shift + Ctrl/Strg + Enter -- Alacritty
Alt/Opt + j or k -- switch focus
Alt/Opt + 1 or 2 or ... -- switch workspace
Shift + Alt/Opt + c -- close window
