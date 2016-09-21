#include <stdio.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

/* The function we'll call from the lua script */
int
average (lua_State *l)
{
	/* get number of arguments */
	int n = lua_gettop (l);
	double sum = 0;
	int i;

	/* loop through each argument */
	for (i = 1; i <= n; i++) {
		if (!lua_isnumber (l, i)) {
			lua_pushstring (l, "Incorrect argument to 'average'");
			lua_error (l);
		}

		/* total the arguments */
		sum += lua_tonumber (l, i);
	}

	/* clear the stack */
	lua_pop (l, n);

	/* push the average */
	lua_pushnumber (l, sum / n);

	/* push the sum */
	lua_pushnumber (l, sum);

	/* return the number of results */
	return 2;
}


int
main()
{
	/* initialize Lua */
	lua_State *l = luaL_newstate();

	/* load Lua base libraries */
	luaL_openlibs (l);

	/* register our function */
	lua_register (l, "average", average);

	/* run the script */
	luaL_dofile (l, "callback.lua");

	/* cleanup Lua */
	lua_close (l);

	return 0;
}

