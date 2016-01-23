#include "write_char_at.hpp"

#include "windows.h"
#include "stdio.h"

namespace console{

void go_to(math::point2d position){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {
        (short) position.x,
        (short) position.y
    });
}

void write_char_at(math::point2d position, char c){
    go_to(position);
    putchar(c);
}

}