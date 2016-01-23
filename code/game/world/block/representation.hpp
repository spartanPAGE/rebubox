#pragma once

#include "ids.hpp"

#include "console/canvas/console-canvas.hpp"

namespace rebubox{

using block_representation_t = console_field;

constexpr block_representation_t block_representations[] = {
    //empty
    { ' ', console::graphics::color::blue, console::graphics::color::blue },
    //grass
    { char(176), console::graphics::color::green, console::graphics::color::dark_green },
    //stone
    { char(177), console::graphics::color::gray, console::graphics::color::dark_gray }
};

}