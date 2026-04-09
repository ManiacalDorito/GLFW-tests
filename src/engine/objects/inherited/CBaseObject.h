#ifndef CBASEOBJECT_H
#define CBASEOBJECT_H

#include <glm.hpp>
#include <glm/gtx/quaternion.hpp>


class CBaseObject
{

    public:
    glm::vec3 transform{0.0f};
    glm::vec3 rotation{0.0f};
    glm::vec3 scale{0.0f};

    virtual ~CBaseObject() = default;
    virtual void render() const = 0;
    virtual void think(float frameDelta) const = 0;
    
};

#endif