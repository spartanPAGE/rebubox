#include "main-loop.hpp"

namespace rebubox{

void start_main_loop(
    main_loop::update_func update, 
    main_loop::drawing_func draw,
    main_loop::game_ending_func end_game
){
    main_loop::frame_t frame = 1;
    while(!end_game(frame)){
        update(frame);
        draw(frame);
        frame += 1;
    }
}

}