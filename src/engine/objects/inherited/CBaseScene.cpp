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






    void AddObject(std::unique_ptr<CBaseObject> obj)
    {
        objectList.push_back(std::move(obj)); // move shifts ownership of a unique pointer.
        // this is how we avoid memory issues in c! Very nice!
    }

    void DeleteObject(std::unique_ptr<CBaseObject> obj)
    {
        for (auto it = objectList.begin(); it != objectList.end(); ) {
            if ((*it)) {         // suppose you have a flag
                it = objectList.erase(it); // erase returns next iterator
            } else {
                ++it;
            }
        }
    }

    /// @brief Call the render function on each CBaseObject in scene
    void RenderScene()
    {
        for (auto item: )
        {

        }
    }

    /// @brief Call the think function on each CBaseObject
    void CallThink()
    {

    }

};

