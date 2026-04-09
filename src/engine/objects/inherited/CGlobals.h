#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Globals
{
    public:
    static GLFWwindow* globalWindowPointer;
    static int windowWidth;
    static int windowHeight;

    static unsigned int shaderPrograms[10];

    static bool debugMode;
};

enum class ShaderProgramEnum {
    BASIC, // use default genericLit shader program
    PBR,
    PHONG,
    UNLIT
};

enum class DebugRenderEnum {
    RENDER_WIREFRAME = 8,
    RENDER_FULLBRIGHT = 16,
    RENDER_ONLY_ENTITIES = 32
};

enum class DebugTextDrawEnum {
    SHOW_DEV_WARNINGS = 8,
    SHOW_ERROR_WARNINGS = 16
};