#include "Creeper.h"


namespace SmallGame {
	namespace gameObject {
		Creeper::Creeper()
		{
			m_Damage = 1400;
			m_Range = 200;
		}

		Creeper::Creeper(int damage, int range)
		{
			m_Damage = damage;
			m_Range = range;
		}

		void Creeper::explosion()
		{
			std::cout << "Explode with " << m_Damage
				<< " dmg in radius " << m_Range << std::endl;
		}

		int Creeper::getDamage()
		{
			return m_Damage;
		}
		int Creeper::getRange()
		{
			return m_Range;
		}
	}
}