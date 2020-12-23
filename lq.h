#ifndef lq_h
#define lq_h

#include "lua.h"
#include "lvm.h"
#include "lobject.h"

int luaQ_generic_error(lua_State *L);
void lua_pushqcfunction (lua_State *L, lua_qCFunction fn);

#define luaQ_newfunction(name) static int name(StkId func)

#define luaQ_init() int __counter = 1;

#define makeerrcode(arg, tag) \
  ((tag << 8) | arg)

#define luaQ_error(arg, tag) {                        \
    setfvalue(s2v(func), luaQ_generic_error);  \
    return makeerrcode(arg, tag);                     \
}

#define luaQ_checknumber(n) {               \
  if (!tonumber(s2v(func + __counter), &n)) \
    luaQ_error(__counter, LUA_TNUMBER);     \
  __counter++;                              \
}

#define luaQ_checkinteger(n) {                \
  if (!tointeger(s2v(func + __counter), &n))  \
    luaQ_error(__counter, LUA_TNUMBER);       \
  __counter++;                                \
}

#define luaQ_returnnumber(n) {  \
  setfltvalue(s2v(func), n);  \
  return 0;                   \
}

#define luaQ_returninteger(n) {   \
  setivalue(s2v(func), n);      \
  return 0;                     \
}

#endif
