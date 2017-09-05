#include "Monster.h"
namespace SmallGame {
	namespace gameObject {
		Monster::Monster()
		{
			m_Health = 1000;
			m_Mana = 200;
			m_damage = 1000;
		}

		void Monster::setDamage(int newDamage)
		{
			m_damage = newDamage;
		}

		int Monster::getDamage() {
			return m_damage;
	}
	}
}