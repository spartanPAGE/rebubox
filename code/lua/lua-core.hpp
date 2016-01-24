#pragma once

extern "C"{

#include <lua/lua.h>
#include <lua/lualib.h>
#include <lua/lauxlib.h>

}

namespace rebubox{

struct lua_core{
    lua_State *state = nullptr;
    void init();
    void add_path(const char *);
    void def(lua_CFunction, const char *);
    void load_file(const char *);
    void exec(const char *);
    void run(size_t number_of_args, size_t number_of_returns, int errfunc_idx);
    void pick_global(const char *);
    void traceback();
    void finish();
};

}