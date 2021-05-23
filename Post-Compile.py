#   For some strange reason, if the FinalBIN file does not exist yet,
#   You have to do a "Clean" before "Build" or it doesn't get copied...
#
#   If the file exists, it gets updated...
#
#   This is rather odd...

print(">---------- POST Compile Script BEGIN ----------<")

Import("env", "projenv")
from shutil import copyfile

Import("env")

my_flags = env.ParseFlags(env['BUILD_FLAGS'])

my_cppdefines = my_flags.get("CPPDEFINES")

MyName = my_cppdefines[1][1]
MyType = my_cppdefines[2][1]
MyBuild = env['PIOENV']

Foo1 = env['PROGNAME'] + ".bin"
Foo2 = env['PIOENV'] + ".bin"

# FinalBIN = "Distribution/" + env['PIOENV'] + ".bin"
FinalBIN = "Distribution/" + MyName + " (" + MyType + " _ " + MyBuild + ").bin"

# print(Foo1, " --> ", Foo2, " ==> ", FinalBIN)
print(Foo1, " --> ", FinalBIN)

def Copy_Binary(*args, **kwargs):
    print(">---------- POST Compile Script ----------<")
    print("Copying binary to distribution directory...", FinalBIN)
    print(">---------- POST Compile Script ----------<")
    target = str(kwargs['target'][0])
    copyfile(target, FinalBIN)
    print("Done.")

env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", Copy_Binary)   #post action for .hex

print(">---------- POST Compile Script END ----------<")
