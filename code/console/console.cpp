#include "console.hpp"

#include "windows.h"

void console::set_cursor_visibility(bool state){
    static auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(handle, &cursorInfo);
    cursorInfo.bVisible = state; // set the cursor visibility
    SetConsoleCursorInfo(handle, &cursorInfo);
}