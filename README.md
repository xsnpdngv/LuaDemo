Lua Demo
========

Simple example to demondstrate how to call Lua functions from C

Build
-----

```bash
git clone <URL>
cd luademo
make
```

Run
---

```bash
# ./lua_demo <Lua_file> <Lua_func> [<Lua_arg1>[, ...]]
./lua_demo foo.lua bar "Hello world"
./lua_demo foo.lua baz "Hello" "world"
```
