#include "console-canvas.hpp"

bool operator!=(const console_field &st, const console_field &nd){
    return !(st.c == nd.c
        && st.fcol == nd.fcol
        && st.bgcol == nd.bgcol);
}