#pragma once

#include <string>

namespace console{

struct input_buffer{
    static std::string data;
    static void collect();
    static void clear();
};

}