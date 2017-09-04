//
#include "BaseGameObject.h"

namespace SmallGame
{
    namespace GameObject
    {

        unsigned int BaseGameObject::OBJECT_COUNT = 0;

        BaseGameObject::BaseGameObject()
        {
            m_ObjectId = ++OBJECT_COUNT;
        }

    }
}