#pragma once

namespace SmallGame
{
    namespace GameObject
    {

        class BaseGameObject
        {
        protected:
            unsigned int m_ObjectId;
        private:
            static unsigned int OBJECT_COUNT;

        public:
            BaseGameObject();

            inline unsigned int getObjectId() { return m_ObjectId; }
            inline static unsigned int getObjectCount() { return OBJECT_COUNT; }
        };

        enum ObjectType
        {

        };

    }
}
