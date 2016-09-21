#include <stdio.h>

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

	lua_createtable (l, 0, 4);

	lua_pushstring (l, "name");
	lua_pushstring (l, "Richard");
	lua_settable (l, -3);  /* 3rd element from the stack top */

	lua_pushstring (l, "date");
	lua_pushstring (l, "2016-08-15");
	lua_settable (l, -3);

	lua_pushstring (l, "ip");
	lua_pushstring (l, "10.0.0.1");
	lua_settable (l, -3);

	lua_pushstring (l, "custom");
	lua_pushstring (l, "wibble");
	lua_settable (l, -3);

        lua_setglobal (l, "mytable");

	/* run the script */
	luaL_dofile (l, "array.lua");

	/* cleanup Lua */
	lua_close (l);

	return 0;
}

