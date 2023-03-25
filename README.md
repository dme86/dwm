
![enter image description here](https://dwm.suckless.org/dwm.svg)

# dwm - dynamic window manager

[dwm](https://dwm.suckless.org/) is an extremely fast, small, and dynamic (tiling) window manager for [X](https://www.x.org/).

![enter image description here](https://i.imgur.com/s5LXSdd.png)

## install

### Arch (btw)

**Dependencies**

    pacman -S base-devel git dmenu libpulse playerctl dunst feh libx11 libxft xorg-server xorg-xinit libxinerama neovim ttf-meslo-nerd alacrtity pacman-contrib terminus-font

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

## pacman hooks

I've configured a `PostTransaction` [hook](https://wiki.archlinux.org/title/pacman#Hooks) on Arch:

**/etc/pacman.d/hooks/dwmblocks.hook**:

    [Trigger]
    Operation = Upgrade
    Type = Package
    Target = *
    
    [Action]
    Description = Restarting dwmblocks after upgrade...
    When = PostTransaction
    Exec = pkill -RTMIN+25 dwmblocks
    
It reloads the script inside the statusbar after `pacman -Syu`.
To use it like this you need to configure `HookDir = /etc/pacman.d/hooks/` in your `/etc/pacman.conf`.

## intercepting notebook charging events on arch linux with dunstify

To intercept the charging event of your notebook on Arch Linux and use `dunstify` to show a notification, you can follow these steps:

1. Install `acpid` if it's not already installed:

		sudo pacman -S acpid
		
Start the `acpid` daemon and enable it to start at boot:

    sudo systemctl start acpid.service
    sudo systemctl enable acpid.service

Change `/etc/acpi/handler.sh` to your needs, eg:

```bash
#!/bin/bash

case "$1" in
    ac_adapter)
        case "$2" in
            AC|ACAD|ADP0)
                case "$4" in
                    00000000)
                        # AC adapter unplugged
                        ;;
                    00000001)
                        # AC adapter plugged in
                        DISPLAY=:0 dunstify "Notebook is charging"
                        ;;
                esac
                ;;
        esac
        ;;
esac
```

Reload `acpid` to apply the changes:

	sudo systemctl reload acpid.service



## wallpapers

My wallpapers are stored inside `$HOME/.wallpapers` - just clone them from [github](https://github.com/dme86/.wallpapers). In my setups i'm using those two lines of bash to choose an wallpaper from that folder and set it via [feh](https://github.com/derf/feh) as a background:

    img=(`find ~/.wallpapers/ -name '*' -exec file {} \; | grep -o -P '^.+: \w+ image' | cut -d':' -f1`)
    feh --bg-scale "${img[$RANDOM % ${#img[@]} ]}"

It depends from where you have to call this script. On systems with a login manager i would put it inside `~/.xprofile`. If you don't use a [display manager](https://wiki.archlinux.org/title/display_manager) you can put it inside `~/.xinitrc`.

## multi-monitor setups

I often use multiple monitors and there fore [autorandr](https://github.com/phillipberndt/autorandr), which enables me to automatically hot-plug external displays.

## Keybindings


| Key | Description |
|--|--|
|`Shift + Ctrl/Strg + Enter`  |Start Terminal `alacritty`|
|`Alt/Opt + p`|Open [dmenu](https://tools.suckless.org/dmenu/)|
|`Alt/Opt +` `j` or `k`|Switch window focus|
|`Alt/Opt + Enter`|Switches the primary window and stack|
|`Alt/Opt + m`|Change the [layout](https://dwm.suckless.org/tutorial/) to `monocle` so the windows will be maximized|
|`Alt/Opt + 1` or `2` or `3` or ...|Switch workspace|
|`Shift + Alt/Opt + 1` or `2` or `3` or ...|Move active window to another workspace|
|`Shift + Alt/Opt + c`|Close window|
|`Alt/Opt + b`|Hide/Show titlebar|
|`Alt/Opt +` `,` or `.`|If you are using multiple displays those commands will change the focussed monitor. I recommend [arandr](https://github.com/chrysn/arandr) if you have a multi-monitor setup.|
|`Alt/Opt + Shift + Space`|Toggle floating mode on the active window. Alt/Opt right mouse key for resizing, Alt/Opt left mouse key for moving the window|
