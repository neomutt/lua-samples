#include <stdio.h>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

/* the Lua interpreter */
lua_State* l;

int main()
{
	/* initialize Lua */
	l = luaL_newstate();

	/* load Lua base libraries */
	luaL_openlibs(l);

        /* set some default values */
        lua_pushinteger (l, 10);
        lua_setglobal (l, "apple");
        lua_pushinteger (l, 20);
        lua_setglobal (l, "banana");
        lua_pushinteger (l, 30);
        lua_setglobal (l, "cherry");

	/* run the script */
	luaL_dofile(l, "lua4.lua");
	luaL_dofile(l, "lua4.lua");
	luaL_dofile(l, "lua4.lua");

	/* cleanup Lua */
	lua_close(l);

	return 0;
}

