#include "set_colors.hpp"

#include "windows.h"

void console::set_color(graphics::color foreground, graphics::color background){
    auto fval = static_cast<WORD>(foreground), gval = static_cast<WORD>(background);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fval | (gval << 4));
}