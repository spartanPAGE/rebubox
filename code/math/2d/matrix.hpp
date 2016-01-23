#pragma once
#include <vector>
#include <iterator>

namespace math{

template<typename T>
struct matrix2d{
    matrix2d(size_t width, size_t height):
        _width(width),
        _height(height),
        _data(width*height){}

    auto width() const{ return _width; }

    auto height() const{ return _height; }

    auto *operator[](size_t idx){ return (&_data[0]) + (idx * _height); }
    const auto *operator[](size_t idx) const{ return _data.data() + (idx * _height); }

    auto begin(){ return std::begin(_data); }
    auto begin() const{ return std::begin(_data); }

    auto end(){ return std::end(_data); }
    auto end() const{ return std::end(_data); }
private:
    size_t _width, _height;
    std::vector<T> _data;
};

}