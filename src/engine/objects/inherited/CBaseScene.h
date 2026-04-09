#ifndef CBASESCENE_H
#define CBASESCENE_H

#include <glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <list>
#include <memory>
#include "objects/CBaseObject.h"

class Scene
{
    public:
    std::list< std::unique_ptr<CBaseObject> > objectList;

    void RenderScene();
    void CallThink();
    void AddObject(std::unique_ptr<CBaseObject> obj);
    void DeleteObject(std::unique_ptr<CBaseObject> obj);
};

#endif