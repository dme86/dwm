![enter image description here](https://dwm.suckless.org/dwm.svg)

# dwm - dynamic window manager

[dwm](https://dwm.suckless.org/) is an extremely fast, small, and dynamic (tiling) window manager for [X](https://www.x.org/).

![enter image description here](https://i.imgur.com/s5LXSdd.png)

## install

### Arch (btw)

**Dependencies**

    pacman -S base-devel git dmenu libpulse playerctl dunst libx11 libxft xorg-server xorg-xinit libxinerama neovim ttf-meslo-nerd alacrtity pacman-contrib terminus-font

**Clone from this repo**

    git clone https://github.com/dme86/dwm.git

**Modify xinit**

    echo "exec dwm" > ~/.xinitrc

**build dwm**

    cd dwm/
    make install

**build dwmblocks**

    cd dwm/dwmblocks-async
    make dwmblocks
    make install

Run `startx` to start dwm incl dwmblocks.

## Keybindings


| Key | Description |
|--|--|
|`Shift + Ctrl/Strg + Enter`  |Start Terminal `alacritty`|
|`Alt/Opt + p`|Open [dmenu](https://tools.suckless.org/dmenu/)|
|`Alt/Opt +` `j` or `k`|Switch window focus|
|`Alt/Opt + Enter`|Switches the primary window and stack|
|`Alt/Opt + 1` or `2` or `3` or ...|Switch workspace|
|`Shift + Alt/Opt + 1` or `2` or `3` or ...|Move active window to another workspace|
|`Shift + Alt/Opt + c`|Close window|
|`Alt/Opt + b`|Hide/Show titlebar|