#pragma once

#include "console/canvas/console-canvas.hpp"

#include "satirev/singleton.h"

namespace rebubox{

using canvas_singleton = satirev::singleton<console_canvas>;

void draw_at_canvas_xy(int x, int y, char c, int fcol, int bgcol);

}
