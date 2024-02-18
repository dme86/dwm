
![dwm logo](https://dwm.suckless.org/dwm.svg)

# dwm - dynamic window manager

This is my version of [dwm](https://dwm.suckless.org/) - an extremely fast, small, and dynamic (tiling) window manager for [X](https://www.x.org/).
I chose dwm over other tiling window managers because its defaults work really well for me, so I don't have to patch it much.

|Floating  | Full/Terminal |
|--|--|
| ![enter image description here](https://i.imgur.com/Ss6nZM1.png) |![enter image description here](https://i.imgur.com/Pp9EvNb.png)  |

I am utilizing a customized iteration of dwmblocks to showcase pertinent information, including the current kernel version. 
These scripts are both straightforward and sophisticated; an icon signals the need for a system reboot, and a small `+` icon indicates the availability of upgraded packages, particularly if there's a newer kernel version among them. 
Additionally, the weather script employs IP-based location detection and leverages Nerd Fonts to present aesthetically pleasing glyphs.
![enter image description here](https://i.imgur.com/OzzNp2Z.png) 

For me, the greatest feature of tiling window managers like dwm is the ability to modify how my windows are displayed using my keyboard - fullscreen, side by side, stacked, and even floating windows are possible.
See also "[keybindings](#keybindings)".

## install

I would recommend having some basic knowledge of Linux before trying out dwm (or any other tiling window manager). However, the installation process is simple. I have written down a list of dependencies for my system, so if you want to use my setup, make sure you have those packages installed.

### Arch (btw)

**Dependencies**

> I also use my own version of [st](https://github.com/dme86/st) (simple terminal), but you can choose
> another one if you prefer. Just make sure you have configured it in
> your `config.h` file accordingly.

    pacman -S base-devel git dmenu libpulse playerctl dunst feh libx11 libxft xorg-server xorg-xinit libxinerama neovim ttf-meslo-nerd pacman-contrib terminus-font

**Clone from this repo**

```bash
git clone https://github.com/dme86/dwm.git
```

**Modify xinit**

```bash
echo "exec dwm" > ~/.xinitrc
```
**build dwm**

```bash
cd dwm/
make install
```

**build dwmblocks**

```bash
cd dwm/dwmblocks-async
make dwmblocks
make install
```

Run `startx` to start dwm incl dwmblocks.

## patching


The defaults of dwm suit me really well, and I only use a few patches.
[Patching dwm](https://dwm.suckless.org/patches/) is quite straightforward. I download the diff file into my [patch folder](https://github.com/dme86/dwm/tree/main/patches) and apply it using, for example:

```bash
patch < patches/dwm-pertag-6.2.diff
```

Usually, the patch should work [OOTB](https://en.wikipedia.org/wiki/Out_of_the_box_%28feature%29). If not, you have to fix it. If you want to remove a patch that didn't work, you can do it using, for example:

```bash
patch -R < patches/dwm-pertag-6.2.diff`
```

You need to recompile dwm after applying or removing a patch.

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
    Exec = /bin/sh -c "/usr/bin/pkill -RTMIN+25 dwmblocks && /usr/bin/pkill -RTMIN+24 dwmblocks"

It reloads the update indicator script inside the statusbar after `pacman -Syu`.
To use it like this you need to configure `HookDir = /etc/pacman.d/hooks/` in your `/etc/pacman.conf`.

## intercepting notebook charging events on arch linux with dunstify

To intercept the charging event of your notebook on Arch Linux and use `dunstify` to show a notification, you can follow these steps:

Install `acpid` if it's not already installed:

```bash
sudo pacman -S acpid
```

Start the `acpid` daemon and enable it to start at boot:

```bash
sudo systemctl start acpid.service
sudo systemctl enable acpid.service
```

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

```bash
sudo systemctl reload acpid.service
```


## wallpapers

My wallpapers are stored inside `$HOME/.wallpapers` - just clone them from [github](https://github.com/dme86/.wallpapers). In my setups i'm using those two lines of bash to choose an wallpaper from that folder and set it via [feh](https://github.com/derf/feh) as a background:

```bash
img=(`find ~/.wallpapers/ -name '*' -exec file {} \; | grep -o -P '^.+: \w+ image' | cut -d':' -f1`)
feh --bg-scale "${img[$RANDOM % ${#img[@]} ]}"
```

It depends from where you have to call this script. On systems with a login manager i would put it inside `~/.xprofile`. If you don't use a [display manager](https://wiki.archlinux.org/title/display_manager) you can put it inside `~/.xinitrc`.

## multi-monitor setups

I often use multiple monitors and there fore [autorandr](https://github.com/phillipberndt/autorandr), which enables me to automatically hot-plug external displays.

## keybindings

I mostly use dwm defaults here because I'm used to them, and I like the workflow out of the box. However, you're free to figure out what works best for you.

| Key | Description |
|--|--|
|`Shift + Ctrl/Strg + Enter`  |Start Terminal [st](https://github.com/dme86/st)|
|`Alt/Opt + p`|Open [dmenu](https://tools.suckless.org/dmenu/)|
|`Alt/Opt +` `j` or `k`|Switch window focus|
|`Alt/Opt + Enter`|Switches the primary window with stack|
|`Alt/Opt + t`|Change the [layout](https://dwm.suckless.org/tutorial/) to `tiling` (dwm default)|
|`Alt/Opt + m`|Change the [layout](https://dwm.suckless.org/tutorial/) to `monocle` so the windows will be maximized|
|`Alt/Opt + Shift + Space`|Toggle `floating` mode on the active window. `Alt/Opt` + `right mouse key` for resizing, `Alt/Opt` + `left mouse key` for moving the window|
|`Alt/Opt` + `h` or `l`|Changes the ratio between the primary and stack correspondingly|
|`Alt/Opt + 1` or `2` or `3` or ...|Switch workspace|
|`Shift + Alt/Opt + 1` or `2` or `3` or ...|Move active window to another workspace|
|`Shift + Alt/Opt + c`|Close window|
|`Alt/Opt + b`|Hide/Show titlebar|
|`Alt/Opt +` `,` or `.`|If you are using multiple displays those commands will change the focussed monitor. I recommend [arandr](https://github.com/chrysn/arandr) if you have a multi-monitor setup.|
|`Alt/Opt +`|Increase Gap-size. `tiling` mode only|
|`Alt/Opt -`|Decrease Gap-size. `tiling` mode only|
