#include "python.hpp"

#include <boost/python.hpp>

#include <cstdlib>

#include "game/canvas/console-canvas-singleton.hpp"

namespace rebubox{

void python_interpreter::init(){
    using namespace boost::python;
    guard([&]{
        Py_Initialize();
        Py_SetProgramName(L"");
        Py_InitializeEx(0);

        main_module = boost::python::import("__main__");
        main_namespace = main_module.attr("__dict__");

        main_namespace["rebubox_draw_at_canvas_xy"] = make_function(&rebubox::draw_at_canvas_xy);

        boost::python::exec_file("rebubox/scripts/main.py", main_namespace);
        boost::python::exec_file("rebubox/scripts/update.py", main_namespace);
        pyupdate = main_namespace["update"];
    });
}

void python_interpreter::guard(std::function<void()> f){
    try{
        f();
    }
    catch(const boost::python::error_already_set &){
        PyErr_Print();
        std::exit(EXIT_FAILURE);
    }
}

}