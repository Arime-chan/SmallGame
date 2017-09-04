//
#include "Mob.h"

namespace SmallGame
{
    namespace gameObject
    {
        Mob::Mob()
        {
            // let's assume every DEFAULT mob has the same stat;
            m_Type = -1;
            m_Health = 100;
            m_Mana = 20;
        }

        void Mob::attack()
        {
            // TODO: code attack logic here;
        }

        void Mob::move(int offsX, int offsY)
        {
            // TODO: code movement logic here;
        }
    }
}
