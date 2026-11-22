package project;

private typedef LuaJITState = hl.Abstract<"lua_State">;

class LuaJIT {
    @:hlNative('hlluajit', 'version')
    private static function _VERSION():hl.Bytes { return null; }
    public static function VERSION():String { return @:privateAccess String.fromUTF8(_VERSION()); }

    @:hlNative('hlluajit', 'release')
    private static function _RELEASE():hl.Bytes { return null; }
    public static function RELEASE():String { return @:privateAccess String.fromUTF8(_RELEASE()); }

    @:hlNative('hlluajit', 'lua_l_newstate')
    public static function newstate():LuaJITState { return null; }

    @:hlNative('hlluajit', 'lua_l_openlibs')
    public static function openlibs(state:LuaJITState):Void {}

    @:hlNative('hlluajit', 'lua_l_dostring')
    private static function _dostring(state:LuaJITState, string:hl.Bytes):Int {return 0;}
    public static function dostring(state:LuaJITState, string:String):Int { return _dostring(state, haxe.io.Bytes.ofString(string)); }

    @:hlNative('hlluajit', 'lua_close')
    public static function close(state:LuaJITState):Void {}
}