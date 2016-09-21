#include <stdio.h>
#include <string.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#define VERSION "0.7"

int
main()
{
	/* initialize Lua */
	lua_State *l = luaL_newstate();

	/* load Lua base libraries */
	luaL_openlibs (l);

	lua_pushstring (l, VERSION);
	lua_setglobal (l, "VERSION");

	luaL_dofile (l, "pass-variable.lua");

	/* cleanup Lua */
	lua_close (l);

	return 0;
}

