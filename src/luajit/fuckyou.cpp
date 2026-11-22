#define HL_NAME(n) hlluajit_##n
#include <hl.h>
#include <cstring>
#include <lua.hpp>

extern "C" {
    #define _LUA_STATE _ABSTRACT(lua_State)

    vbyte* make_hl_utf8(const char *utf8_str) {
        int len = (int)strlen(utf8_str);
        return hl_copy_bytes((const vbyte*)utf8_str, len + 1);
    }

    // VERSION
    HL_PRIM vbyte* HL_NAME(version)() {
        return make_hl_utf8(LUA_VERSION);
    }
    DEFINE_PRIM(_BYTES, version, _NO_ARG);

    // RELEASE
    HL_PRIM vbyte* HL_NAME(release)() {
        return make_hl_utf8(LUA_RELEASE);
    }
    DEFINE_PRIM(_BYTES, release, _NO_ARG);

    // luaL_newstate
    HL_PRIM lua_State* HL_NAME(lua_l_newstate)() {
        lua_State* state = luaL_newstate();
        return state;
    }
    DEFINE_PRIM(_LUA_STATE, lua_l_newstate, _NO_ARG);

    // luaL_openlibs
    HL_PRIM void HL_NAME(lua_l_openlibs)(lua_State* state) {
        luaL_openlibs(state);
    }
    DEFINE_PRIM(_VOID, lua_l_openlibs, _LUA_STATE);

    // luaL_dostring
    HL_PRIM int HL_NAME(lua_l_dostring)(lua_State* state, vbyte* string) {
        return luaL_dostring(state, (char*)string);
    }
    DEFINE_PRIM(_I32, lua_l_dostring, _LUA_STATE _BYTES);

    // lua_close
    HL_PRIM void HL_NAME(lua_close)(lua_State* state) {
        lua_close(state);
    }
    DEFINE_PRIM(_VOID, lua_close, _LUA_STATE);
}