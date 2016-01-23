#pragma once

#include <functional>

namespace rebubox{

namespace main_loop{
    using frame_t = std::uint64_t;

    using action_func = std::function<void(frame_t)>;

    using update_func = action_func;
    using drawing_func = action_func;
    using game_ending_func = std::function<bool(frame_t)>;
}

    void start_main_loop(
        main_loop::update_func, 
        main_loop::drawing_func, 
        main_loop::game_ending_func
    );
}