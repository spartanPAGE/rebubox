#pragma once

#include "block/ids.hpp"

#include "math/2d/matrix.hpp"

namespace rebubox{

class world{
public:
    using block_t = world_block_id;
    using blocks_t = math::matrix2d<block_t>;
public:
    world(size_t w, size_t h);

    blocks_t &get_blocks();
    const blocks_t &get_blocks() const;
private:
    const size_t width, height;
    blocks_t blocks;
};

}