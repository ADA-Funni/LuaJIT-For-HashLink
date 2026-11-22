#define HL_NAME(n) hlluajit_##n
#include <hl.h>

#include <iostream>

extern "C" {
    #include <lua.h>
    #include <luajit.h>
    #include <lualib.h>
    #include <lauxlib.h>
}

static int helloWorldLua(lua_State* l) {
    return 1;
}

HL_PRIM vstring* HL_NAME(hello_world)(vstring* hello)
{
    lua_State* state = luaL_newstate();
    luaL_openlibs(state);
    luaJIT_setmode(state, 0, LUAJIT_MODE_ON);

    lua_register(state, "helloWorld", helloWorldLua);

    const char* code = "local result = helloWorld(\"I am a string\")\nprint(\"result is: \" .. result)";

    if (luaL_dostring(state, code) != LUA_OK) {
        printf("Lua error: %s", lua_tostring(state, -1));
        lua_pop(state, 1);
    }

    lua_close(state);
    return hello;
}
DEFINE_PRIM(_STRING, hello_world, _STRING);