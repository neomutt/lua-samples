#include <stdio.h>
#include <string.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#define VERSION "0.7"

int
main()
{
	/* the Lua interpreter */
	lua_State *l;

	/* initialize Lua */
	l = luaL_newstate();

	/* load Lua base libraries */
	luaL_openlibs (l);

	lua_pushstring (l, VERSION);
	lua_setglobal (l, "VERSION");

	luaL_dofile (l, "lua3.lua");

	/* cleanup Lua */
	lua_close (l);

	return 0;
}

