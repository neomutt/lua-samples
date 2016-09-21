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

	luaL_dofile (l, "return-value.lua");

	int n = lua_gettop (l);
	printf ("stack = %d\n", n);
	printf ("num = %lld\n", lua_tointeger (l, 1));

	/* cleanup Lua */
	lua_close (l);

	return 0;
}

