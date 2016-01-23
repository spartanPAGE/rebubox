#include "color.hpp"

namespace console{
namespace graphics{

color darker(color c){
    switch(c){
    case color::black:
        return color::black;
    case color::white:
        return color::white;
    case color::blue:
        return color::dark_blue;
    case color::green:
        return color::dark_green;
    case color::cyan:
        return color::dark_cyan;
    case color::red:
        return color::dark_red;
    case color::magenta:
        return color::dark_magenta;
    case color::yellow:
        return color::dark_yellow;
    case color::gray:
        return color::dark_gray;
    }

    return color::black;
}

}
}