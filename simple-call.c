#include <stdio.h>
#include <string.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int
main()
{
	/* initialize Lua */
	lua_State *l = luaL_newstate();

	/* load Lua base libraries */
	luaL_openlibs (l);

	luaL_dofile (l, "simple-call.lua");

	/* cleanup Lua */
	lua_close (l);

	return 0;
}

