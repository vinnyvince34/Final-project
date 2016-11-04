#pragma once
/*Vincent Alexander Seliang
*CS02
*2001585562*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <chrono>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

//class for exception

class InvalidRace
{};

class InvalidJob
{};

//Initializing class for Weapon

class Weapon
{
private:
	string nWName;
	int nWHealth;
	int nWMana;
	int nWAttack;
	int nWDefence;
	int nWMagicAttack;
	int nWMagicDefence;
	int nWAgility;
	int nWLuck;
public:
	Weapon(string name, int health, int mana, int attack, int defence, int magic_attack, int magic_defence, int agility, int luck)
	{
		nWName = name;
		nWHealth = health;
		nWMana = mana;
		nWAttack = attack;
		nWDefence = defence;
		nWMagicAttack = magic_attack;
		nWMagicDefence = magic_defence;
		nWAgility = agility;
		nWLuck = luck;
	}
	Weapon()
	{
		nWName = "";
		nWHealth = 0;
		nWMana = 0;
		nWAttack = 0;
		nWDefence = 0;
		nWMagicAttack = 0;
		nWMagicDefence = 0;
		nWAgility = 0;
		nWLuck = 0;
	}
	string wGetName()
	{
		return nWName;
	}
	int wGetAttack()
	{
		return nWAttack;
	}
	int wGetMagicAttack()
	{
		return nWMagicAttack;
	}
};

//Weapon(string name, int health, int mana, int attack, int defence, int magic_attack, int magic_defence, int agility, int luck)

Weapon aWeapon[15] = {
	Weapon("Cheap Sword", 0, 0, 4, 1, 0, 0, 0, 0),
	Weapon("Decent Sword", 0, 0, 5, 1, 0, 0, 0, 0),
	Weapon("Good Sword", 0, 0, 7, 2, 0, 0, 0, 0),
	Weapon("Cheap Staff", 0, 5, 1, 0, 2, 1, 0, 0),
	Weapon("Decent Staff", 0, 6, 1, 0, 3, 1, 0, 0),
	Weapon("Good Staff", 0, 8, 2, 0, 5, 2, 0, 0),
	Weapon("Cheap Gun", 0, 0, 3, 0, 0, 0, 2, 0),
	Weapon("Decent Gun", 0, 0, 4, 0, 0, 0, 2, 0),
	Weapon("Good Gun", 0, 0, 6, 0, 0, 0, 4, 0),
	Weapon("Cheap Dagger", 0, 0, 1, 0, 0, 0, 2, 2),
	Weapon("Decent Dagger", 0, 0, 2, 0, 0, 0, 3, 2),
	Weapon("Good Dagger", 0, 0, 4, 0, 0, 0, 5, 3),
	Weapon("Cheap Whip", 0, 0, 3, 0, 1, 0, 1, 3),
	Weapon("Decent Whip", 0, 0, 4, 0, 2, 0, 2, 3),
	Weapon("Good Whip", 0, 0, 5, 0, 3, 0, 3, 5),
};

Weapon weapon;

string DisplayWeaponName(int index)
{
	return aWeapon[index].wGetName();
}

//Initializing class for Armor

class Armor
{
private:
	string sAName;
	int nAHealth;
	int nAMana;
	int nAAttack;
	int nADefence;
	int nAMagicAttack;
	int nAMagicDefence;
	int nAAgility;
	int nALuck;
public:
	Armor(string name, int health, int mana, int attack, int defence, int magic_attack, int magic_defence, int agility, int luck)
	{
		sAName = name;
		nAHealth = health;
		nAMana = mana;
		nAAttack = attack;
		nADefence = defence;
		nAMagicAttack = magic_attack;
		nAMagicDefence = magic_defence;
		nAAgility = agility;
		nALuck = luck;
	}
	Armor()
	{
		sAName = "";
		nAHealth = 0;
		nAMana = 0;
		nAAttack = 0;
		nADefence = 0;
		nAMagicAttack = 0;
		nAMagicDefence = 0;
		nAAgility = 0;
		nALuck = 0;
	}
	string aGetName()
	{
		return sAName;
	}
	int aGetDefense()
	{
		return nADefence;
	}
	int aGetMagicDefense()
	{
		return nAMagicDefence;
	}
};

//Armor(string name, int health, int mana, int attack, int defence, int magic_attack, int magic_defence, int agility, int luck)

Armor aArmor[15] = {
	Armor("Cheap Mail", 20, 0, 0, 4, 0, 0, -1, 0),
	Armor("Decent Mail", 20, 0, 0, 5, 0, 0, -2, 0),
	Armor("Good Mail", 40, 0, 0, 8, 0, 0, -2, 0),
	Armor("Cheap Robe", 0, 20, 0, 1, 1, 2, 0, 0),
	Armor("Decent Robe", 0, 20, 0, 1, 2, 3, 0, 0),
	Armor("Good Robe", 0, 40, 0, 3, 4, 5, 0, 0),
	Armor("Cheap Jumpsuit", 0, 0, 0, 2, 0, 2, 1, 1),
	Armor("Decent Jumpsuit", 0, 0, 0, 3, 0, 2, 2, 2),
	Armor("Good Jumpsuit", 0, 0, 0, 4, 0, 2, 2, 2),
	Armor("Cheap Garb", 0, 0, 0, 2, 0, 0, 2, 3),
	Armor("Decent Garb", 0, 0, 0, 2, 0, 0, 4, 5),
	Armor("Good Garb", 0, 0, 0, 3, 0, 0, 8, 7),
	Armor("Cheap Noble Suit", 0, 0, 1, 2, 1, 0, 0, 2),
	Armor("Decent Noble Suit", 0, 0, 0, 1, 3, 0, 0, 2),
	Armor("Good Noble Suit", 0, 0, 0, 3, 5, 2, 0, 6)
};

Armor armor;

string DisplayArmorName(int index)
{
	return aArmor[index].aGetName();
}
//Initializing class for the player

class Player

{
private:
	string sPlayerName;
	int nHealth = 0;
	int nMana = 0;
	int nCurrency = 500;
	int nJob;
	int nRace;
	int nLevel = 1;
	int nEXP = 0;
	int nAttack = 0;
	int nDefence = 0;
	int nMagicAttack = 0;
	int nMagicDefence = 0;
	int nAgility = 0;
	int nLuck = 0;
	Weapon nWeapon;
	Armor nArmor;
public:
	Player(int job, int race, int health, int mana, int attack, int defence, int magic_attack, int magic_defence, int agility, int luck, Weapon *weapon, int weaponnum, Armor *armor, int armornum)
	{
		nJob = job;
		nRace = race;
		nHealth = health;
		nMana = mana;
		nAttack = attack;
		nDefence = defence;
		nMagicAttack = magic_attack;
		nMagicDefence = magic_defence;
		nAgility = agility;
		nLuck = luck;
		nWeapon = *(weapon + weaponnum);
		nArmor = *(armor + armornum);
	}
	Player()
	{
		nJob = 0;
		nRace = 0;
		nHealth = 0;
		nMana = 0;
		nAttack = 0;
		nDefence = 0;
		nMagicAttack = 0;
		nMagicDefence = 0;
		nAgility = 0;
		nLuck = 0;
		nWeapon = aWeapon[0];
		nArmor = aArmor[0];
	}
	void SetStatus(int health, int mana, int attack, int defence, int magic_attack, int magic_defence, int agility, int luck)
	{
		nHealth += health;
		nMana += mana;
		nAttack += attack;
		nDefence += defence;
		nMagicAttack += magic_attack;
		nMagicDefence += magic_defence;
		nAgility += agility;
		nLuck += luck;
		return;
	}
	void JobIncrementer(int health, int mana, int attack, int defence, int magic_attack, int magic_defence, int agility, int luck, Weapon *weapon, int weaponnum, Armor *armor, int armornum)
	{
		nHealth += health;
		nMana += mana;
		nAttack += attack;
		nDefence += defence;
		nMagicAttack += magic_attack;
		nMagicDefence += magic_defence;
		nAgility += agility;
		nLuck += luck;
		nWeapon = *(weapon + weaponnum);
		nArmor = *(armor + armornum);
		return;
	}
	void SetName(string name)
	{
		sPlayerName = name;
		return;
	}
	void SetRace(int race)
	{
		nRace = race;
		return;
	}
	void SetJob(int job)
	{
		nJob = job;
		return;
	}
	void SetWeapon(int weapon)
	{
		*(aWeapon + weapon);
		return;
	}
	void SetArmor(int armor)
	{
		*(aArmor + armor);
		return;
	}
	string GetName()
	{
		return sPlayerName;
	}
	int GetLevel()
	{
		return nLevel;
	}
	int GetHealth()
	{
		return nHealth;
	}
	int GetMana()
	{
		return nMana;
	}
	int GetAttack()
	{
		return nAttack;
	}
	int GetDefence()
	{
		return nDefence;
	}
	int GetMagicAttack()
	{
		return nMagicAttack;
	}
	int GetMagicDefence()
	{
		return nMagicDefence;
	}
	int GetAgility()
	{
		return nAgility;
	}
	int GetLuck()
	{
		return nLuck;
	}
	int GetAJob()
	{
		return nJob;
	}
	void GetData()
	{
		cout << "Health: " << nHealth << endl;
		cout << "Mana: " << nMana << endl;
		cout << "Attack: " << nAttack << endl;
		cout << "Defence: " << nDefence << endl;
		cout << "Magic Attack: " << nMagicAttack << endl;
		cout << "Magic Defence: " << nMagicDefence << endl;
		cout << "Agility: " << nAgility << endl;
		cout << "Luck: " << nLuck << endl;
		return;
	}
	void Leveling(int exp)
	{
		nEXP += exp;
		int LevelUp = (nLevel * 2) + 50;
		if (nEXP >= LevelUp)
		{
			cout << "Level up!" << endl;
			cout << "You leveled up from " << nLevel << " to " << nLevel << "!" << endl;
			nLevel++;
			if (nRace == 1)
			{
				nHealth += 3;
				nMana += 2;
				nAttack += 2;
				nDefence += 2;
				nMagicAttack += 2;
				nMagicDefence += 2;
				nAgility += 2;
				nLuck += 2;
			}
			else if (nRace == 2)
			{
				nHealth += 1;
				nMana += 4;
				nAttack += 1;
				nDefence += 1;
				nMagicAttack += 3;
				nMagicDefence += 3;
				nAgility += 2;
				nLuck += 3;
			}
			else if (nRace == 3)
			{
				nHealth += 3;
				nMana += 1;
				nAttack += 3;
				nDefence += 2;
				nMagicAttack += 1;
				nMagicDefence += 1;
				nAgility += 1;
				nLuck += 2;
			}
			else if (nRace == 4)
			{
				nHealth += 5;
				nMana += 1;
				nAttack += 4;
				nDefence += 4;
				nMagicAttack += 1;
				nMagicDefence += 1;
				nAgility += 2;
				nLuck += 1;
			}
			else
			{
				nHealth += 1;
				nMana += 3;
				nAttack += 2;
				nDefence += 1;
				nMagicAttack += 2;
				nMagicDefence += 2;
				nAgility += 4;
				nLuck += 4;
			}
			nEXP = 0;
		}
		return;
	}
};

//Reminder about race variable:
//1 - Human
//2 - Elf
//3 - Dwarf
//4 - Orc
//5 - Halfling

//Reminder about job variable:
//1 - Knight
//2 - Mage
//3 - Mechanic
//4 - Thief
//5 - Noble

Player player;

//Initializing class for enemies

class Enemy
{
private:
	string sEName;
	int nEHealth;
	int nEMana;
	int nEAttack;
	int nEDefence;
	int nEMagicAttack;
	int nEMagicDefence;
	int nEAgility;
	int nELuck;
	int nEXPGain;
public:
	Enemy(string name, int health, int mana, int attack, int defence, int magic_attack, int magic_defence, int agility, int luck, int exp)
	{
		this->sEName = name;
		this->nEHealth = health;
		this->nEMana = mana;
		this->nEAttack = attack;
		this->nEDefence = defence;
		this->nEMagicAttack = magic_attack;
		this->nEMagicDefence = magic_defence;
		this->nEAgility = agility;
		this->nELuck = luck;
		this->nEXPGain = exp;
	}
	Enemy()
	{
		this->sEName = "";
		this->nEHealth = 0;
		this->nEMana = 0;
		this->nEAttack = 0;
		this->nEDefence = 0;
		this->nEMagicAttack = 0;
		this->nEMagicDefence = 0;
		this->nEAgility = 0;
		this->nELuck = 0;
		this->nEXPGain = 0;
	}
	string eGetName()
	{
		return sEName;
	}
	int eGetHealth()
	{
		return nEHealth;
	}
	int eGetMana()
	{
		return nEMana;
	}
	int eGetAttack()
	{
		return nEAttack;
	}
	int eGetDefence()
	{
		return nEDefence;
	}
	int eGetMagicAttack()
	{
		return nEMagicAttack;
	}
	int eGetMagicDefence()
	{
		return nEMagicDefence;
	}
	int eGetAgility()
	{
		return nEAgility;
	}
	int eGetLuck()
	{
		return nELuck;
	}
	int eGetEXP()
	{
		return nEXPGain;
	}
};

//Enemy(int health, int mana, int attack, int defence, int magic_attack, int magic_defence, int agility, int luck, int exp)
Enemy enemy[10] = {
	Enemy("Slime", 50, 10, 6, 6, 6, 4, 4, 2, 6),
	Enemy("Bat", 40, 20, 8, 6, 3, 3, 6, 2, 6),
	Enemy("Snake", 60, 10, 8, 8, 2, 2, 6, 4, 10),
	Enemy("Gazer", 100, 30, 4, 4, 10, 4, 4, 4, 15),
	Enemy("Bandit", 150, 20, 12, 7, 3, 5, 6, 2, 20),
	Enemy("Troll", 300, 20, 18, 15, 6, 6, 6, 7, 30),
	Enemy("Goblin", 100, 30, 6, 6, 6, 6, 10, 6, 10),
	Enemy("Skeleton", 150, 30, 10, 15, 3, 3, 3, 3, 20),
	Enemy("Wolf", 145, 15, 8, 4, 4, 2, 12, 3, 20),
	Enemy("Dragon", 500, 70, 20, 20, 15, 10, 8, 5, 100)
};
