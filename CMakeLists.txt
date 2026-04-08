cmake_minimum_required(VERSION 3.10)
project(mainGLFW)



find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME} src/main.c)

# has to be named after the main file
target_link_libraries(${PROJECT_NAME} PRIVATE glfw OpenGL::GL)