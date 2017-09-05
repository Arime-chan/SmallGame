#pragma once

#include "BaseGameObject.h"

namespace SmallGame
{
    namespace gameObject
    {
        class Mob : public BaseGameObject
        {
		protected:
            int m_Type; // type of this mob: player, enemy, npc, ...;
            int m_Health; // hp of this mob: assume this mob have HP;
            int m_Mana; // mp of this mob: assume this mob can use spells;

            BaseGameObject* m_Target; // the main target of this mob: assume the mob can locks on ONE target;

        public:
            Mob();

            /** This mob attacks its pre-chosen target.
              *
              */
            void attack();

            /** This mob moves a small (or big) distance.
              *
              * \param offsX the X offset to move the mob.
              * \param offsY the Y offset to move the mob.
              */
            void move(int offsX, int offsY);

        };
    }
}
