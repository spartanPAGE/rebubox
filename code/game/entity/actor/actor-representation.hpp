#pragma once

#include "console/canvas/console-canvas.hpp"

#include "math/2d/matrix.hpp"

namespace rebubox{
   
using actor_representation_block_t = console_field;
using actor_representation_t = math::matrix2d<actor_representation_block_t>;

}