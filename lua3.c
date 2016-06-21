#include <stdio.h>
#include <string.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#define VERSION "0.7"

/* the Lua interpreter */
lua_State* L;

int main()
{
        /* initialize Lua */
        L = luaL_newstate();

        /* load Lua base libraries */
	luaL_openlibs(L);

	lua_pushstring(L, VERSION);
	lua_setglobal(L, "VERSION");

	luaL_dofile (L, "lua3.lua");

        /* cleanup Lua */
        lua_close(L);

        return 0;
}

