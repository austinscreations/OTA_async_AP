print(">---------- PRE Compile Script BEGIN ----------<")

Import("env")

# Dump construction environments (for debug purpose)
# print(env.Dump())

# access to global construction environment
# print(env)

print("=======")
print("BUILD FLAGS: ")
print(env.ParseFlags(env['BUILD_FLAGS']))
print("=======")

print("PIOENV: ", env['PIOENV'])

# env.Replace(PROGNAME=env['PIOENV'])

print(">---------- PRE Compile Script END ----------<")
