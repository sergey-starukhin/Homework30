#include <string>
#include <iostream>
#pragma once

using namespace std;

class Player
{
private:
	string name;
	int hp;

public:
	Player(const string& name_, int hp_) : name(name_), hp(hp_) {}

	//getters
	string getName() const;
	int getHp() const;

	//setters
	void takeDamage(int damage);

	//predicates
	bool isAlive() const;

	//operators
	friend ostream& operator<<(ostream& out, Player player)
	{
		out << player.name << "(HP : " << player.hp << ")" << endl;
		return out;
	}
};

inline string Player::getName() const {
	return name;
}

inline int Player::getHp() const {
	return hp;
}

inline void Player::takeDamage(int damage) {
	if (damage > hp)
		hp = 0;
	else
		hp -= damage;
}

inline bool Player::isAlive() const {
	return hp > 0;
}
