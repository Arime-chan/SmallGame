#pragma once

#include <iostream>
#include "Mob.h"


namespace SmallGame {
	namespace gameObject{
		class Creeper : public Mob {
		protected:
			int m_Damage;
			int m_Range;

		public:
			Creeper();
			Creeper(int damage, int range);
			void explosion();

			int getDamage();
			int getRange();
	};
	
	}
}
