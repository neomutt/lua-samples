#include <stdio.h>
#include <string.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

/* the Lua interpreter */
lua_State* L;

int main()
{
        /* initialize Lua */
        L = luaL_newstate();

        /* load Lua base libraries */
	luaL_openlibs(L);

	luaL_dofile (L, "lua1.lua");

        /* cleanup Lua */
        lua_close(L);

        return 0;
}

