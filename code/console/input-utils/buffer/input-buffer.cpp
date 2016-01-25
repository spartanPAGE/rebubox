#include "input-buffer.hpp"

#include "console/input-utils/keyboard/get_key.hpp"
#include "console/input-utils/keyboard/key_pressed.hpp"

namespace console{

std::string input_buffer::data = "";

void input_buffer::collect(){
    while(console::key_pressed()){
        data += console::get_key();
    }
}

void input_buffer::clear(){
    input_buffer::data.clear();
}

}