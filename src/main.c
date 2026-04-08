#include <GLFW/glfw3.h>
#include <stdio.h>

int main(void)
{
    printf("Test\n");

    // hints for window location on creation
    GLFWmonitor* mainMonitor = glfwGetPrimaryMonitor();
    
    
    if (!glfwInit())
    {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 640, "Main Window", mainMonitor, NULL);
    if (window == NULL) return -1;

    // This means make active opengl context in this window
    glfwMakeContextCurrent(window);

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();

    }

    glfwTerminate();
    return 0;
}