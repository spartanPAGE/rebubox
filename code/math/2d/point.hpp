#pragma once
#include <string>
namespace math{

struct point2d{
    int x, y;

    std::string str() const;
};

bool operator==(const point2d &first, const point2d &second);
bool operator!=(const point2d &first, const point2d &second);

}