/**
 * @file     lua_demo.c
 * @brief    sample C module to demonstrate Lua function invocation
 * @author   Tamas Dezso
 * @date     March 3, 2017
 * @version  1.0
 */


#include <stdio.h>
#include <stdlib.h>

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>


int main(int argc, char *argv[])
{
    lua_State *L; /* Lua context */
    int retN;     /* number of Lua return values */
    int i;        /* general index */

    /* process arguments */
    if(argc < 3)
    {
        fprintf(stderr, "usage: %s <Lua_file> <Lua_func> [<Lua_arg1> ...]\n", argv[0]);
        exit(1);
    }

    /* initialize Lua context, open libs */
    if((L = luaL_newstate()) == NULL)
    {
        fprintf(stderr, "Cannot create new Lua state\n");
        exit(2);
    }
    luaL_openlibs(L);

    /* load Lua script file */
    if(luaL_dofile(L, argv[1]))
    {
        fprintf(stderr, "Error loading Lua script file: %s\n",
                lua_tostring(L, -1));
        exit(3);
    }

    /* empty stack */
    lua_settop(L, 0);

    /* push function name and arguments into stack */
    lua_getglobal(L, argv[2]);
    for(i = 3; i < argc; ++i)
        lua_pushstring(L, argv[i]);

    /* execute Lua function with the number of arguments pushed into stack and
       3 as the (maximal) number of possible return values */
    if(lua_pcall(L, argc - 3, 3, 0) != LUA_OK)
    {
        fprintf(stderr, "Lua function call failure: %s\n", lua_tostring(L, -1));
        exit(2);
    }

    /* evaluate return values */
    for(i = 1, retN = lua_gettop(L); i <= retN; ++i)
    {
        /* if there is an integer value */
        if(lua_isinteger(L, i))
        {
            fprintf(stdout, "ret:\t%d\n", (int)lua_tointeger(L, i));
            /* ... */
            continue;
        }

        /* if there is a string */
        if(lua_isstring(L, i))
        {
            fprintf(stdout, "ret:\t'%s'\n", lua_tostring(L, i));
            /* ...  */
            continue;
        }

        /* if there is a table */
        if(lua_istable(L, i))
        {
            fprintf(stdout, "table return value...\n");
            /* ... */
            continue;
        }
    }

    /* destroy Lua state */
    lua_close(L);
    exit(0);
} /* main */
