#include <stdio.h>
#include <string.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int
main()
{
	/* the Lua interpreter */
	lua_State* l;

	/* initialize Lua */
	l = luaL_newstate();

	/* load Lua base libraries */
	luaL_openlibs (l);

	luaL_dofile (l, "lua5.lua");

	int n = lua_gettop (l);
	printf ("stack = %d\n", n);
	printf ("num = %lld\n", lua_tointeger (l, 1));

	/* cleanup Lua */
	lua_close (l);

	return 0;
}

