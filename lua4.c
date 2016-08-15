#include <stdio.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

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

        lua_pushglobaltable(l);       // Get global table
        lua_pushnil(l);               // put a nil key on stack
        while (lua_next(l,-2) != 0) { // key(-1) is replaced by the next key(-1) in table(-2)
		const char *name = lua_tostring(l,-2);  // Get key(-2) name
		if (lua_isnumber (l, -1)) {
			int val = -1;
			val = lua_tointeger (l, -1);
			printf ("%s = %d\n", name, val);
		}
		lua_pop(l,1);               // remove value(-1), now key on top at(-1)
        }
        lua_pop(l,1);                 // remove global table(-1)

        // printf ("APPLE  = %d\n", lua_getglobal (l, "apple"));
        // printf ("BANANA = %d\n", lua_getglobal (l, "banana"));
        // printf ("CHERRY = %d\n", lua_getglobal (l, "cherrx"));
        // int a = -42;
        // printf ("APPLE  = %d\n", lua_geti (l, 3, &a));
        // printf ("APPLE  = %d\n", a);

	/* cleanup Lua */
	lua_close(l);

	return 0;
}

