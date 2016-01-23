#include "point.hpp"

namespace math{

std::string point2d::str() const{
    return std::string("{") + std::to_string(x) + ", " + std::to_string(y) + "}";
}

bool operator==(const point2d &first, const point2d &second){
    return first.x == second.x && first.y == second.y;
}

bool operator!=(const point2d &first, const point2d &second){
    return !(first == second);
}

}