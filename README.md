
# dwm - dynamic window manager

dwm is an extremely fast, small, and dynamic tiling window manager for [X](https://www.x.org/).

![enter image description here](https://i.imgur.com/s5LXSdd.png)

## install

### Arch (btw)

**Dependencies**
`pacman -S base-devel git libx11 libxft xorg-server xorg-xinit libxinerama neovim ttf-meslo-nerd alacrtity pacman-contrib terminus-font`

**Clone from this repo**
`git clone https://github.com/dme86/dwm.git`

**Modify xinit**
`echo "exec dwm" > ~/.xinitrc`


**build dwm**
`cd dwm/`
`make install`

**build dwmblocks**
`cd dwm/dwmblocks-async`
`make dwmblocks`
`make install`

Run `startx` to start dwm inkl dwmblocks.

## Keybindings


| Key | Description |
|--|--|
|`Shift + Ctrl/Strg + Enter`  |Start Terminal `alacritty`  |
|`Alt/Opt +` `j` or `k`|Switch window focus|
|`Alt/Opt + 1` or `2` or `3` or ...|Switch workspace|
|`Shift + Alt/Opt + c`|Close window|
|`Alt/Opt + b`|Hide/Show titlebar|

