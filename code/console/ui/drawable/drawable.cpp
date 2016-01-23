#include "drawable.hpp"

drawable::drawable(target_t &t): target(t){}

void drawable::draw(){

}

drawable::target_t &drawable::access_target(){
    return target;
}