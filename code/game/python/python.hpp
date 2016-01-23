#pragma once
#include <boost/python.hpp>
#include <functional>

namespace rebubox{

struct python_interpreter{
    boost::python::object main_module;
    boost::python::object main_namespace;
    boost::python::object pyupdate;

    void init();

    void guard(std::function<void()> f);
};

}