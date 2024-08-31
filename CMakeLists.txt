# Project name
project(tbin)

# Specify the C standard (optional, but recommended)
set(CMAKE_C_STANDARD 99)

# Add the executable target and specify the source files
add_executable(tbin
    src/main.c
    src/argparse.c
    src/translate.c
    src/exit.c
)

# Specify the installation directory
# By default, this will install to /usr/local/bin on Unix systems
install(TARGETS tbin
    RUNTIME DESTINATION bin
)
