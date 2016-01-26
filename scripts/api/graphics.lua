local graphics = {}

graphics.color = {
  black = 0,
    dark_blue = 1,
    dark_green = 2,
    dark_cyan = 3,
    dark_red = 4,
    dark_magenta = 5,
    dark_yellow = 6,
    gray = 7,
    dark_gray = 8,
    blue = 9,
    green = 10,
    cyan = 11,
    red = 12,
    magenta = 13,
    yellow = 14,
    white = 15
}

graphics.console_width = 85
graphics.console_height = 20

function graphics.draw_at(x, y, char, fgcol, bgcol)
  rebubox_draw_at(x, y, char, fgcol, bgcol)
end

return graphics