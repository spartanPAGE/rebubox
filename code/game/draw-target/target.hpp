#pragma once

#include "console/canvas/console-canvas.hpp"

namespace rebubox{

using draw_target_t = console_canvas;
using focused_draw_target_t = draw_target_t &;
using draw_target_view_t = const draw_target_t &;

}