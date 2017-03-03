-- @file    foo.lua
-- @brief   sample Lua script file to demonstrate invocation from C
-- @author  Tamas Dezso
-- @date    March 3, 2017

function bar(a)
    print("Lua:", a)
    return 127
end

function baz(a, b)
    print("Lua:", a, b)
    return "qux"
end
