#include <glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include "CMesh.h"
#include "CEnums.h"



// each one holds a mesh.
// mesh holds VBO, vertices, shader program
class CBaseObject
{

    public:
    glm::vec3 transform{0.0f};
    glm::vec3 rotation{0.0f};
    glm::vec3 scale{0.0f};
    bool queuedForDeletion=false;
    float nextThinkTime=0.0f;
    float thinkInterval=50.0f;
    ShaderProgramEnum ShaderProgram = ShaderProgramEnum::BASIC; // CBaseObjects use
    // default shader program BY DEFAULT (very easy to implement!)
    Mesh objectMesh;

    virtual ~CBaseObject() = default;
    virtual void render() const = 0; // by setting to zero, we say inheritors MUST implement!!!
    // very good for things like render and think!
    virtual void think(float frameDelta) const = 0;
    virtual void setup() const = 0;
    
};

