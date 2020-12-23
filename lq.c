#include "lauxlib.h"
#include "lq.h"
#include "lapi.h"
#include <stdio.h>

int luaQ_generic_error(lua_State *L) {
	int err = lua_tointeger(L, -1);
	int tag = (err & 0xFF00) >> (8);
	int arg = err & 0xFF;

    luaL_typeerror(L, arg, lua_typename(L, tag));
	return 0;
}

void lua_pushqcfunction (lua_State *L, lua_qCFunction fn) {
	setqfvalue(s2v(L->top), fn);
	api_incr_top(L);
}
