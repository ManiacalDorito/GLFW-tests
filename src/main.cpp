// MAKE SURE THESE TWO ARE IN THIS ORDER
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

// prototypes
void processInput(GLFWwindow* window);
// this is a callback to when the window is resized
void windowResized(GLFWwindow* window, int width, int height);

void MainLoopRenderFunc(GLFWwindow* window);


const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
""
"void main()\n"
"{\n"
"    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
""
"void main()\n"
"{\n"
"    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\0" ;


int main(void)
{
    printf("Test\n");

    // hints for window location on creation
    GLFWmonitor* mainMonitor = glfwGetPrimaryMonitor();
    
    
    if (!glfwInit())
    {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Main Window", mainMonitor, NULL);
    if (window == NULL) return -1;

    // This means make active opengl context in this window
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }

    // This establishes the viewport of opengl to the same size as opened window
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    // Glfw has a bunch of useful callbacks like this! Remember!
    glfwSetWindowSizeCallback(window, windowResized);


    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        
        processInput(window);

        // RENDER CODE GOES HERE
        MainLoopRenderFunc(window);


        glfwPollEvents();
        glfwSwapBuffers(window);
        

    }

    glfwTerminate();
    return 0;
}


void windowResized(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

void MainLoopRenderFunc(GLFWwindow* window)
{
    // call draw on each mesh attribute of each CBaseObject
    //for(test )
}