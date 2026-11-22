package;

import project.LuaJIT;

class Main {
    static function main() {
        var l = LuaJIT.newstate();
        LuaJIT.openlibs(l);

        LuaJIT.dostring(l, 'print("hello world")');

        LuaJIT.close(l);
        trace(LuaJIT.VERSION());
    }
}