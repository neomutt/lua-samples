int top = lua_gettop(L);
luaL_loadstring(L, "return 3, 4, 5");
int R = lua_pcall(L, 0, LUA_MULTRET, 0);
int nresults = lua_gettop(L) - top;
