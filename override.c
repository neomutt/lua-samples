#include <stdio.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

/* The function we'll call from the lua script */
int
my_print (lua_State *l)
{
	/* get number of arguments */
	int n = lua_gettop (l);

	printf ("my_print: %d args\n", n);
	int i;

	/* loop through each argument */
	for (i = 1; i <= n; i++) {
		printf ("\t%s\n", lua_tolstring (l, i, NULL));
	}

	/* clear the stack */
	lua_pop (l, n);
	return 0;
}


int
main()
{
	/* initialize Lua */
	lua_State *l = luaL_newstate();

	/* load Lua base libraries */
	luaL_openlibs (l);

	/* override the built-in print function */
	lua_register (l, "print", my_print);

	/* run the script */
	luaL_dofile (l, "override.lua");

	/* cleanup Lua */
	lua_close (l);

	return 0;
}

