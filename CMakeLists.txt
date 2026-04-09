cmake_minimum_required(VERSION 3.10)
project(mainGLFW)



find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)



add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/glad.c
)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# has to be named after the main file
target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
    glfw
    OpenGL::GL
)

# this tells our includes that data is in this folder
target_include_directories(${PROJECT_NAME} PRIVATE include)