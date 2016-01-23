#pragma once

#include "math/2d/utils/buffered_canvas.hpp"
#include "console/graphics-utils/graphics-utils.hpp"

struct console_field{
    char c;
    console::graphics::color fcol, bgcol;
};

bool operator!=(const console_field &, const console_field &);

using console_canvas = math::buffered_canvas<console_field>;