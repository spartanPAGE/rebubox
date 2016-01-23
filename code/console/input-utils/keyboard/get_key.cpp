#include "get_key.hpp"

#include "conio.h"

namespace console{

key get_key(){
    return _getch();
}

}