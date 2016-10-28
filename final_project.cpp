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

//Initializing structure for Weapon

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
};

//Weapon(string name, int health, int mana, int attack, int defence, int magic_attack, int magic_defence, int agility, int luck)

Weapon weapon[15] = {
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

//Initializing structure for Armor

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
};

//Armor(string name, int health, int mana, int attack, int defence, int magic_attack, int magic_defence, int agility, int luck)

Armor armor[15] = {
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

//Initializing structure for the player

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
	Weapon weapon;
	Armor armor;
public:
	Player(int job, int race, int health, int mana, int attack, int defence, int magic_attack, int magic_defence, int agility, int luck)
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
	void JobIncrementer(int health, int mana, int attack, int defence, int magic_attack, int magic_defence, int agility, int luck)
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
	void SetName(string name)
	{
		sPlayerName = name;
		return;
	}
	int SetRace(int race)
	{
		nRace = race;
		return 0;
	}
	int SetJob(int job)
	{
		nJob = job;
		return 0;
	}
	string GetName()
	{
		return sPlayerName;
	}
	int GetLevel()
	{
		return nLevel;
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
	int Leveling(int exp)
	{
		nEXP += exp;
		int LevelUp = ((nLevel * 50) / 2) + 10;
		if (nEXP >= LevelUp)
		{
			cout << "Level up!" << endl;
			cout << "You leveled up from " << nLevel - 1 << " to " << nLevel << "!";
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
		return 0;
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
};

//Enemy(int health, int mana, int attack, int defence, int magic_attack, int magic_defence, int agility, int luck, int exp)
Enemy eArray[10] = {
					Enemy("Slime", 30, 10, 3, 3, 3, 2, 2, 1, 3),
					Enemy("Bat", 20, 20, 4, 3, 4, 3, 3, 1, 3),
					Enemy("Snake", 30, 10, 5, 2, 2, 2, 3, 2, 5),
					Enemy("Gazer", 40, 30, 2, 2, 5, 2, 2, 2, 5),
					Enemy("Bandit", 50, 20, 5, 3, 2, 2, 3, 2, 7),
					Enemy("Troll", 75, 20, 7, 10, 3, 3, 5, 3, 10),
					Enemy("Goblin", 30, 30, 3, 3, 3, 3, 5, 6, 5),
					Enemy("Skeleton", 50, 30, 5, 5, 3, 3, 3, 1, 10),
					Enemy("Wolf", 45, 10, 4, 2, 2, 2, 6, 3, 10),
					Enemy("Dragon", 100, 70, 13, 10, 15, 10, 10, 5, 50)
				   };


//Function prototypes

int PlayerDamage(Player* ppDamage);
int EnemyDamage(Enemy* peDamage);
void PlayerCreation();
void Story();
void ChoiceOne();
void ChoiceOneOne();
void ChoiceTwo();

//Function to create the player

void PlayerCreation()
{
	cout << "Welcome to the your Simple Adventure!" << endl;
	cout << "Before we continue, can you please tell your name?" << endl;
	string sPlaceName;
	getline(cin, sPlaceName);
	player.SetName(sPlaceName);
	cout << "What are you?" << endl;
	cout << "1.Human" << setw(10) << "2.Elf" << setw(10) << "3.Dwarf" << setw(10) << "4.Orc" << setw(15) << "5.Halfling" << endl;
	cout << "Enter 1-5." << endl;
	int nPlaceRace;
	cin >> nPlaceRace;
	player.SetRace(nPlaceRace);
	if (nPlaceRace < 1 || nPlaceRace > 5)
	{
		cout << "Race not found, exiting game...";
		return;
	}
	else if (nPlaceRace == 1)
	{
		cout << player.GetName() << " the human." << endl;
		player.SetStatus(100, 50, 5, 5, 5, 5, 5, 5);
		player.GetData();
	}
	else if (nPlaceRace == 2)
	{
		cout << player.GetName() << " the elf." << endl;
		player.SetStatus(70, 120, 2, 3, 8, 8, 8, 7);
		player.GetData();
	}
	else if (nPlaceRace == 3)
	{
		cout << player.GetName() << " the dwarf." << endl;
		player.SetStatus(120, 40, 7, 5, 3, 2, 4, 5);
		player.GetData();
	}
	else if (nPlaceRace == 4)
	{
		cout << player.GetName() << " the orc." << endl;
		player.SetStatus(150, 20, 10, 8, 1, 2, 6, 3);
		player.GetData();
	}
	else
	{
		cout << player.GetName() << " the halfling." << endl;
		player.SetStatus(50, 80, 6, 3, 4, 6, 10, 7);
		player.GetData();
	}
	cout << "What is your job?" << endl;
	cout << "1.Knight" << setw(10) << "2.Mage" << setw(15) << "3.Mechanic" << setw(10) << "4.Thief" << setw(10) << "5.Noble" << endl;
	cout << "Enter 1-5." << endl;
	int nPlaceJob;
	cin >> nPlaceJob;
	player.SetJob(nPlaceJob);
	if (nPlaceJob < 1 || nPlaceJob > 5)
	{
		cout << "Job not found, you are fired!";
		return;
	}
	else if (nPlaceJob == 1)
	{
		cout << player.GetName() << " the knight." << endl;
		player.JobIncrementer(50, 10, 3, 3, 1, 1, -2, 2);
		player.GetData();
	}
	else if (nPlaceJob == 2)
	{
		cout << player.GetName() << " the mage." << endl;
		player.JobIncrementer(10, 50, 2, 2, 3, 3, 0, 2);
		player.GetData();
	}
	else if (nPlaceJob == 3)
	{
		cout << player.GetName() << " the mechanic." << endl;
		player.JobIncrementer(30, 30, 1, 2, 1, 2, -3, -1);
		player.GetData();
	}
	else if (nPlaceJob == 4)
	{
		cout << player.GetName() << " the thief." << endl;
		player.JobIncrementer(10, 40, 2, -2, 1, -3, 3, 3);
		player.GetData();
	}
	else
	{
		cout << player.GetName() << " the noble." << endl;
		player.JobIncrementer(25, 40, 1, 1, 1, 1, -1, 5);
		player.GetData();
	}
	cout << "Good luck on your adventure," << player.GetName() << endl << endl;
	return;
}

//Battle System Function

int PlayerDamage(Player* ppDamage)
{
	srand(time(NULL));
	int npDamage = (((ppDamage->GetAttack()) / 2) + 1) - ((ppDamage->GetDefence()) / 2);
	int npRandom = rand() % 10 + 1;
	int npDodge = ((ppDamage->GetAgility()) / (ppDamage->GetLuck())) * npRandom;
	int npRandomMax = ((ppDamage->GetAgility()) / (ppDamage->GetLuck())) * 10;
	int npRandomMin = ((ppDamage->GetAgility()) / (ppDamage->GetLuck())) * 1;
	int npChance = rand() % npRandomMax + npRandomMin;
	if ()
		{
		
		}
	string sName = ppDamage->GetName();
	cout << sName << " suffers " << npDamage << " damage points." << endl;
	return npDamage;
}

int EnemyDamage(Enemy* peDamage)
{
	int neDamage = (((peDamage->eGetAttack()) / 2) + 1) - ((peDamage->eGetDefence()) / 2);
	string sName = peDamage->eGetName();
	cout << sName << " suffers " << neDamage << " damage points." << endl;
	return neDamage;
}

//Game part

void Story()
{
	cout << "Welcome to the Simple World, where you can explore the world and probably be what you want!" << endl;
	cout << "To start off, let say you were enjoying a goblet of ale at a pub named, 'The Bannered Mare'." << endl;
	cout << "You saw a bounty that will reward you handsomely." << endl;
	cout << "What are you going to do?" << endl;
	cout << "1. Take the bounty." << endl;
	cout << "2. Leave the bounty." << endl;
	int nChoiceOne;
	cin >> nChoiceOne;
	if (nChoiceOne < 1 || nChoiceOne > 2)
	{
		for (int i = 0; i > 1 || i < 2; )
		{
			cout << "Choice not found." << endl;
			cout << "You saw a bounty that will reward you handsomely." << endl;
			cout << "What are you going to do?" << endl;
			cout << "1. Take the bounty." << endl;
			cout << "2. Leave the bounty." << endl;
			int nChoiceOne;
			cin >> nChoiceOne;
		}
	}
	else if (nChoiceOne == 1)
	{
		ChoiceOne();
	}
	else
	{
		ChoiceTwo();
	}
}

void ChoiceOne()
{
	cout << "You took the bounty poster." << endl;
	cout << "It says that you will need to venture into a dungeon and\n";
	cout << "search for the Chalice." << endl;
	cout << "Would you like to take it? " << endl;
	cout << "Yes/No?" << endl;
	string sBountyAcceptance;
	cin >> sBountyAcceptance;
	if (sBountyAcceptance == "Yes" || sBountyAcceptance == "yes" || sBountyAcceptance == "1" || sBountyAcceptance == "true" || sBountyAcceptance == "True")
	{
		cout << "You took the bounty." << endl;
		cout << "Your first clue is to head out of the city's wall." << endl;
		ChoiceOneOne();
	}
	else
	{
		ChoiceTwo();
	}
}

void ChoiceOneOne()
{
	cout << "You exited the city and you saw several things that interest you." << endl;
	cout << "Which one would you like to inspect?" << endl;
	cout << "1. The grassy path." << endl;
	cout << "2. The broken carriage." << endl;
	int nChoices;
	cin >> nChoices;
	string sLooting;
	switch (nChoices)
	{
		case 1:
			cout << "You decided to explore the grassy road." << endl;
			cout << "At the end of the road, you were ambushed by a group of bandits." << endl;
			cout << "What are you going to do?" << endl;
			cout << "1. Retaliate" << endl;
			cout << "2. Talk to your way out" << endl;
			int nChoiceOne;
			cin >> nChoiceOne;
			switch (nChoiceOne)
			{
				case 1:

			 		break;
				case 2:
					cout << "You talk your way out" << endl;
					cout << "You told them there is a treasure near the hill not far from the wall" << endl;
					int LuckPar = player.GetLuck();
					if (LuckPar > 10)
					{	
						cout << "You are lucky that those bandits are not the brightest ones." << endl;
						cout << "They thank you and ran off towards the place you told them." << endl;
						cout << "You earn 40 EXP." << endl;
						player.Leveling(40);
						cout << "You decided to wander off further." << endl;
					}
					break;
			}
			break;
		case 2:
			cout << "You approached the torn down carriage." << endl;
			cout << "You inspect it closer." << endl;
			cout << "Among the debris, there is one chest that is intact." << endl;
			cout << "Would you like to inspect the intact chest?" << endl;
			cout << "Yes/No" << endl;
			getline(cin, sLooting);
			if (sLooting == "Yes" || sLooting == "yes" || sLooting == "1" || sLooting == "true" || sLooting == "True")
			{
				cout << "Surprisingly, the chest is not locked." << endl;
				cout << "As you open the chest, you found" << endl;
				cout << "You also found a laying note near the chest." << endl;
			}
			else
			{
				cout << "You leave the chest alone." << endl;
			}
			break;
		default:
			cout << "You are not sure what to do because you can't input the number 1 or 2." << endl;
			cout << "You wander off and ended up right front of the entrance of a dungeon." << endl;
			cout << "Would you go in?" << endl;
			cout << "Yes/No?" << endl;
			string sEnteringDungeon;
			getline(cin, sEnteringDungeon);
			if (sEnteringDungeon == "Yes" || sEnteringDungeon == "yes" || sEnteringDungeon == "1" || sEnteringDungeon == "true" || sEnteringDungeon == "True")
			{
				cout << "You Entered the dungeon." << endl;
				
			}
			else
			{

			}
	}
}

void ChoiceTwo()
{
	cout << "You are not interested with the bounty." << endl;
	cout << "Someone is calling you in the corner of the room." << endl;
	cout << "Would you answer his call?" << endl;
	cout << "Yes/No" << endl;
	string sCalling;
	getline(cin, sCalling);
	if (sCalling == "Yes" || sCalling == "yes" || sCalling == "1" || sCalling == "true" || sCalling == "True")
	{
		cout << "You approached the man." << endl;
		cout << "He seems to be shaddy and a bit suspicious." << endl;
		cout << "He say that he would pay you to enter steal an item from a ruin." << endl;
	}
	else
	{
		cout << "You left the pub." << endl;
		cout << "You decided to left the city." << endl;
		ChoiceOneOne();
	}
}

int main()
{
	srand(time(NULL));
	PlayerCreation();
	Story();
	system("PAUSE");
	return 0;
}