#include "key_pressed.hpp"

#include "conio.h"

namespace console{

bool key_pressed(){
    return _kbhit() != 0;
}

}