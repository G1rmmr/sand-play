cmake_minimum_required(VERSION 3.10)
project(sand-simul C)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

if(APPLE)
    include_directories(/usr/local/include)
    link_directories(/usr/local/lib)
    set(SDL2_TTF_LIBRARIES /usr/local/lib/libSDL2_ttf.dylib)
endif()

add_executable(sand-simul main.c System.c Sand.c)

target_include_directories(sand-simul PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})

target_link_libraries(sand-simul PRIVATE ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})