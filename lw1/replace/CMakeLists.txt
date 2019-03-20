set(SOURCES main.cpp)

add_executable(replace ${SOURCES})

add_custom_command(TARGET replace POST_BUILD COMMAND bash test.sh)
