#define CMDLENGTH 60
#define DELIMITER "  "
#define CLICKABLE_BLOCKS

const Block blocks[] = {
	BLOCK("~/dwm/dwmblocks-async/scripts/battery", 10, 21),
        BLOCK("~/dwm/dwmblocks-async/scripts/internet", 15, 20),
	BLOCK("~/dwm/dwmblocks-async/scripts/weather", 1800, 22),
	BLOCK("date +'%a, %d %b [%H:%M:%S]'",    1,    23),
	BLOCK("~/dwm/dwmblocks-async/scripts/kernel", 86400, 24),
	BLOCK("~/dwm/dwmblocks-async/scripts/pacupdate", 3600, 25)
};
