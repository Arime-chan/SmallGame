#pragma once

#include "Mob.h"

namespace SmallGame {
	namespace gameObject {
		class Monster : public Mob {
		private:
			int m_damage;
			
		public:
			Monster();

			void setDamage(int newDamage);
			int getDamage();
		};
	}
}