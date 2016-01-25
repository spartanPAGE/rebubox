#include "lua-core.hpp"

#include "game/canvas/console-canvas-singleton.hpp"
#include "console/input-utils/buffer/input-buffer.hpp"
#include <iostream>
#include <string>
#include <cmath>

//TODO: refactor this whole file. Maybe some proxies, policies and this kind of bullshit;

//[noresult] rebubox_greet()
int lua_rebubox_greet(lua_State *luastate){
    std::cout << "Hello from the C++ lua_rebubox_greet()!" << std::endl;
    return 0;
}

//[noresult] rebubox_draw_at([num] x, [num] y, [string[0]] character, [num] fgcol, [num] bgcol)
int lua_rebubox_draw_at(lua_State *state){
    int x = (int)std::round(luaL_checknumber(state, 1));
    int y = (int)std::round(luaL_checknumber(state, 2));
    char c = luaL_checkstring(state, 3)[0];
    int fgcol = (int)std::round(luaL_checknumber(state, 4));
    int bgcol = (int)std::round(luaL_checknumber(state, 5));

    rebubox::draw_at_canvas_xy(x, y, c, fgcol, bgcol);
    return 0;
}

//[string] rebubox_input()
int lua_rebubox_input(lua_State *state){
    lua_pushstring(state, console::input_buffer::data.c_str());
    return 1;
}

void bail(lua_State *L, char *msg){
    fprintf(stderr, "\nFATAL ERROR:\n  %s: %s\n\n",
            msg, lua_tostring(L, -1));
    exit(1);
}

namespace rebubox{

void lua_core::init(){
    state = luaL_newstate();

    luaL_openlibs(state);

    def(lua_rebubox_greet, "rebubox_greet");
    def(lua_rebubox_draw_at, "rebubox_draw_at");
    def(lua_rebubox_input, "rebubox_input");
}

void lua_core::add_path(const char *path){
    lua_getglobal(state, "package");
    lua_getfield(state, -1, "path"); // get field "path" from table at top of stack (-1)
    std::string cur_path = lua_tostring(state, -1); // grab path string from top of stack
    cur_path.append(";"); // do your path magic here
    cur_path.append(path);
    lua_pop(state, 1); // get rid of the string on the stack we just pushed on line 5
    lua_pushstring(state, cur_path.c_str()); // push the new one
    lua_setfield(state, -2, "path"); // set the field "path" in table at -2 with value at top of stack
    lua_pop(state, 1); // get rid of package table from top of stack
    // all done!
}

void lua_core::def(lua_CFunction f, const char *name){
    lua_pushcfunction(state, f);
    lua_setglobal(state, name);
}

void lua_core::load_file(const char *filename){
    if(luaL_loadfile(state, filename))
        bail(state, "luaL_loadfile() failed");
}

void lua_core::exec(const char *line){
    luaL_dostring(state, line);
}

void lua_core::run(size_t number_of_args, size_t number_of_returns, int errfunc_idx){
    if(lua_pcall(state, number_of_args, number_of_returns, errfunc_idx))
        bail(state, "lua_pcall() failed");
}

void lua_core::pick_global(const char *name){
    lua_getglobal(state, name);
}

void lua_core::traceback(){
    luaL_traceback(state, state, NULL, 1);
    auto res = lua_tostring(state, -1);
    if(!strcmp(res, ""))
        fprintf(stderr, "%s\n", res);
}

void lua_core::finish(){
    lua_close(state);
}

}