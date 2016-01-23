#include "unget_key.hpp"

#include "conio.h"

namespace console{

void unget_key(key k){
    _ungetch(k);
}

}