cmake_minimum_required(VERSION 3.1)

project(Starter)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

file(GLOB src_files
    "src/*.cpp"
)

add_executable(Starter main.cpp ${src_files})
target_link_libraries(Starter sfml-graphics sfml-audio sfml-window sfml-system)
target_include_directories(Starter PRIVATE src)
