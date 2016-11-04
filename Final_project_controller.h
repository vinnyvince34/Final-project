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

#include "Final_project_model.h"

using namespace std;

//Initializing potions

int nPotion = 10;

//Function prototypes

void Opening();
int PlayerTurn(Player& ppTurn, Enemy& enemy, Weapon& weapon);
int EnemyTurn(Enemy& peTurn, Player& player, Armor& armor);
int SpecialMove(Player& ppTurn, Enemy& enemy, Weapon& weapon);
void BattleSystem(Enemy& enemy, Player& player, Weapon& weapon, Armor& armor);
void Story();
void PlayerCreation();
void ChoiceOne();
void ChoiceOneOne();
void ChoiceTwo();
void ChoiceTwoOne();
void End();
string DisplayArt(ifstream& File);

//Function for taking in ASCII art

string DisplayArt(ifstream& File)
{
	string Lines = "";

	if (File)
	{
		while (File.good())
		{
			string TempLine;
			getline(File, TempLine);
			TempLine += "\n";

			Lines += TempLine;
		}
		return Lines;
	}
	else
	{
		return "File does not exist.";
	}
}

//Function to create opening scene

void Opening()
{
	ifstream inputFile;
	inputFile.open("opening.txt");
	string sTitleArt;
	sTitleArt = DisplayArt(inputFile);
	inputFile.close();
	for (int i = 0; i <= 119; i++)
	{
		cout << "*";
	}
	cout << endl;
	cout << sTitleArt << endl;
	for (int i = 0; i <= 119; i++)
	{
		cout << "*";
	}
	cout << endl;
	int nChoice;
	cout << "  Input your choice in integers" << endl;
	cout << "  1. Start your adventure" << endl;
	cout << "  2. Exit the game" << endl;
	cin >> nChoice;
	cin.ignore();
	switch (nChoice)
	{
	case 1:
		cout << "Have fun!" << endl << endl;
		PlayerCreation();
		break;
	case 2:
		cout << "See you later!" << endl;
		system("PAUSE");
		exit(0);
		break;
	default:
		cout << "See you later!" << endl;
		system("PAUSE");
		exit(0);
		break;
	}
	return;
}

//Function to create the player

void PlayerCreation()
{
	cout << "Welcome to the your Simple Adventure!" << endl;
	cout << "Before we continue, can you please tell your name?" << endl;
	string sPlaceName;
	getline(cin, sPlaceName);
	player.SetName(sPlaceName);
	cout << endl << "What are you?" << endl;
	cout << "1.Human" << setw(10) << "2.Elf" << setw(10) << "3.Dwarf" << setw(10) << "4.Orc" << setw(15) << "5.Halfling" << endl;
	cout << "Enter 1-5." << endl;
	int nPlaceRace;
	cin >> nPlaceRace;
	player.SetRace(nPlaceRace);
	if (nPlaceRace < 1 || nPlaceRace > 5)
	{
		throw InvalidRace();
	}
	try
	{
		if (nPlaceRace == 1)
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
	}
	catch (InvalidRace())
	{
		cout << "Race not found, exiting program..." << endl;
		system("PAUSE");
		exit(0);
	}
	catch (...)
	{
		cerr << "Invalid error, exiting program..." << endl;
		system("PAUSE");
		exit(0);
	}

	cout << endl << "What is your job?" << endl;
	cout << "1.Knight" << setw(10) << "2.Mage" << setw(15) << "3.Mechanic" << setw(10) << "4.Thief" << setw(10) << "5.Noble" << endl;
	cout << "Enter 1-5." << endl;
	int nPlaceJob;
	cin >> nPlaceJob;
	player.SetJob(nPlaceJob);
	if (nPlaceJob < 1 || nPlaceJob > 5)
	{
		throw InvalidJob();
	}
	try
	{
		if (nPlaceJob == 1)
		{
			cout << player.GetName() << " the knight." << endl;
			player.JobIncrementer(50, 10, 3, 3, 1, 1, -2, 2, aWeapon, 0, aArmor, 0);
			weapon = aWeapon[0];
			armor = aArmor[0];
			string WeaponName = aWeapon[0].wGetName();
			string ArmorName = aArmor[0].aGetName();
			cout << "Weapon: " << WeaponName << endl;
			cout << "Armor: " << ArmorName << endl;
			player.GetData();
		}
		else if (nPlaceJob == 2)
		{
			cout << player.GetName() << " the mage." << endl;
			player.JobIncrementer(10, 50, 2, 2, 3, 3, 0, 2, aWeapon, 3, aArmor, 3);
			weapon = aWeapon[3];
			armor = aArmor[3];
			string WeaponName = aWeapon[3].wGetName();
			string ArmorName = aArmor[3].aGetName();
			cout << "Weapon: " << WeaponName << endl;
			cout << "Armor: " << ArmorName << endl;
			player.GetData();
		}
		else if (nPlaceJob == 3)
		{
			cout << player.GetName() << " the mechanic." << endl;
			player.JobIncrementer(30, 30, 1, 2, 1, 2, -3, -1, aWeapon, 6, aArmor, 6);
			weapon = aWeapon[6];
			armor = aArmor[6];
			string WeaponName = aWeapon[6].wGetName();
			string ArmorName = aArmor[6].aGetName();
			cout << "Weapon: " << WeaponName << endl;
			cout << "Armor: " << ArmorName << endl;
			player.GetData();
		}
		else if (nPlaceJob == 4)
		{
			cout << player.GetName() << " the thief." << endl;
			player.JobIncrementer(10, 40, 2, -2, 1, -3, 3, 3, aWeapon, 9, aArmor, 9);
			weapon = aWeapon[9];
			armor = aArmor[9];
			string WeaponName = aWeapon[9].wGetName();
			string ArmorName = aArmor[9].aGetName();
			cout << "Weapon: " << WeaponName << endl;
			cout << "Armor: " << ArmorName << endl;
			player.GetData();
		}
		else
		{
			cout << player.GetName() << " the noble." << endl;
			player.JobIncrementer(25, 40, 1, 1, 1, 1, -1, 5, aWeapon, 12, aArmor, 12);
			weapon = aWeapon[12];
			armor = aArmor[12];
			string WeaponName = aWeapon[12].wGetName();
			string ArmorName = aArmor[12].aGetName();
			cout << "Weapon: " << WeaponName << endl;
			cout << "Armor: " << ArmorName << endl;
			player.GetData();
		}
	}
	catch (InvalidJob())
	{
		cout << "Invalid job, exiting program..." << endl;
		system("PAUSE");
		exit(0);
	}
	catch (...)
	{
		cerr << "Invalid error, exiting program..." << endl;
		system("PAUSE");
		exit(0);
	}
	cout << endl << "Good luck on your adventure, " << player.GetName() << endl << endl;
	return;
}

//Battle System Function

int PlayerTurn(Player& ppTurn, Enemy& enemy, Weapon& weapon)
{
	srand(time(NULL));
	int npDamage;
	int npRandom = rand() % 10 + 1;
	int npRandomDamage = rand() % 3 + 1;
	string spName = ppTurn.GetName();
	string seName = enemy.eGetName();
	if (npRandom > 3)
	{
		npDamage = ((ppTurn.GetAttack()) + (weapon.wGetAttack()) - (enemy.eGetDefence())) * npRandomDamage;
		if (npDamage < 0)
		{
			npDamage = 1;
		}
		cout << seName << " suffers " << npDamage << " damage points." << endl;
	}
	else
	{
		cout << seName << " successfully dodge the attack!" << endl;
		npDamage = 0;
	}
	return npDamage;
}

int EnemyTurn(Enemy& peTurn, Player& player, Armor& armor)
{
	srand(time(NULL));
	int neRandom = rand() % 10 + 1;
	int neRandomDamage = rand() % 3 + 1;
	int neDamage;
	string seName = peTurn.eGetName();
	string spName = player.GetName();
	if (neRandom > 3)
	{
		neDamage = ((peTurn.eGetAttack() + 3) - ((player.GetDefence()) + (armor.aGetDefense()))) * neRandomDamage;
		if (neDamage <= 0)
		{
			neDamage = 1;
		}
		cout << spName << " suffers " << neDamage << " damage points." << endl;
	}
	else
	{
		cout << spName << " successfully dodge the attack!" << endl;
		neDamage = 0;
	}
	return neDamage;
}

int SpecialMove(Player& player, Enemy& enemy, Weapon& weapon)
{
	srand(time(NULL));
	int npRandom = rand() % 10 + 1;
	int npRandomDamage = rand() % 3 + 1;
	int npSpecial;
	int npJob = player.GetAJob();
	string seName = enemy.eGetName();
	string spName = player.GetName();
	switch (npJob)
	{
	case 1:
		cout << "You swing your weapon with high power!" << endl;
		if (npRandom > 3)
		{
			npSpecial = ((((player.GetAttack() + 5) + (weapon.wGetAttack())) - ((enemy.eGetDefence()) / 2))) * npRandomDamage * 2;
			cout << seName << " suffers " << npSpecial << " damage points." << endl;
		}
		else
		{
			cout << spName << " successfully dodge the attack!" << endl;
			npSpecial = 0;
		}
		break;
	case 2:
		cout << "You cast a burning magical spell!" << endl;
		if (npRandom > 3)
		{
			npSpecial = ((player.GetAttack() + 2) - ((enemy.eGetDefence()) / 3)) * npRandomDamage;
			cout << seName << " suffers " << npSpecial << " damage points." << endl;
		}
		else
		{
			cout << spName << " successfully dodge the attack!" << endl;
			npSpecial = 0;
		}
	}

	return npSpecial;
}

void BattleSystem(Enemy& enemy, Player& player, Weapon& weapon, Armor& armor)
{
	srand(time(NULL));
	int nRandomChance;
	string bpName = player.GetName();
	int bpHealth = player.GetHealth();
	int bpMana = player.GetMana();
	int bpAgility = player.GetAgility();
	string beName = enemy.eGetName();
	int beHealth = enemy.eGetHealth();
	int beMana = enemy.eGetMana();
	int beAgility = enemy.eGetAgility();
	cout << enemy.eGetName() << " has appeared!" << endl;
	while (beHealth > 0)
	{
		if (bpHealth <= 0)
		{
			cout << "You died!" << endl;
			exit(0);
		}
		if (beHealth <= 0)
		{
			cout << beName << " has died!" << endl;
			cout << "You earned " << enemy.eGetEXP() << "!";
			player.Leveling(enemy.eGetEXP());
			break;
		}
		cout << "Player HP: " << bpHealth << endl;
		cout << "Player MN: " << bpMana << endl << endl;
		cout << beName << " health: " << beHealth << endl << endl;
		nRandomChance = rand() % 3 + 1;
		cout << "What are you going to do?" << endl;
		cout << "  1. Attack" << endl;
		cout << "  2. Talk" << endl;
		cout << "  3. Use potion" << endl;
		cout << "  4. Use skill" << endl;
		cout << "  4. Escape" << endl;
		int nChoice;
		cin >> nChoice;
		switch (nChoice)
		{
		case 1:
			if (bpAgility >= beAgility)
			{
				beHealth -= PlayerTurn(player, enemy, weapon);
				bpHealth -= EnemyTurn(enemy, player, armor);
			}
			else
			{
				bpHealth -= EnemyTurn(enemy, player, armor);
				beHealth -= PlayerTurn(player, enemy, weapon);
			}
			break;
		case 2:
			cout << "You talk to the " << beName << endl;
			if (player.GetLuck() >= 20 && nRandomChance < 3)
			{
				cout << "You successfully convinced the " << beName << "!" << endl;
				cout << "You gain " << enemy.eGetEXP() << " EXP!" << endl;
				player.Leveling(enemy.eGetEXP());
				break;
			}
			else
			{
				cout << "You failed convinced the " << beName << "!" << endl;
				bpHealth -= EnemyTurn(enemy, player, armor);
			}
			break;
		case 3:
			if (nPotion > 0)
			{
				cout << "You use the potion!" << endl;
				nPotion--;
				if (bpHealth > player.GetHealth() + 30)
				{
					bpHealth += 30;
				}
				else
				{
					bpHealth = player.GetHealth();
				}
			}
			break;
		case 4:
			if (player.GetAJob() == 1)
			{
				if (bpAgility >= beAgility)
				{
					if (bpMana > 0)
					{
						bpMana -= 10;
					}
					else
					{
						cout << "You don't have enough mana!" << endl;
					}
					bpHealth -= EnemyTurn(enemy, player, armor);
				}
				else
				{
					bpHealth -= EnemyTurn(enemy, player, armor);
					if (bpMana > 0)
					{

						bpMana -= 10;
					}
					else
					{
						cout << "You don't have enough mana!" << endl;
					}
				}
			}

			break;
		default:
			cout << "You tried to escape." << endl;
			if (nRandomChance < 3)
			{
				cout << "You successfully escaped!" << endl;
				cout << "You earned 10 EXP!" << endl;
				player.Leveling(10);
				break;
			}
			else
			{
				cout << "You failed to escape!" << endl;
				bpHealth -= EnemyTurn(enemy, player, armor);
			}
			break;
		}
	}
}

//Game part

void Story()
{
	cout << "Welcome to the Simple World, where you can explore the world " << endl;
	cout << "and probably be what you want!" << endl;
	cout << "To start off, let say you were enjoying a goblet of ale at a " << endl;
	cout << "pub named, 'The Bannered Mare'." << endl;
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
		cin.ignore();
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
			BattleSystem(enemy[4], player, weapon, armor);
			cout << "You leave the scene and decided to head out." << endl;
			cout << "You found a cave, you decided to enter it." << endl;
			ChoiceTwoOne();
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
			else
			{
				cout << "You failed to convinced the bandit" << endl;
				cout << "The bandit attacks you!" << endl;
				BattleSystem(enemy[4], player, weapon, armor);
				cout << "You leave the scene and decided to head out." << endl;
				cout << "You found a cave, you decided to enter it." << endl;
			}
			ChoiceTwoOne();
			break;
		}
		break;
	case 2:
		srand(time(NULL));
		int nProbabilityItem = rand() % 35 + 0;
		cout << "You approached the torn down carriage." << endl;
		cout << "You inspect it closer." << endl;
		cout << "Among the debris, there is one chest that is intact." << endl;
		cout << "Would you like to inspect the intact chest?" << endl;
		cout << "Yes/No" << endl;
		getline(cin, sLooting);
		if (sLooting == "Yes" || sLooting == "yes" || sLooting == "1" || sLooting == "true" || sLooting == "True")
		{
			cout << "Surprisingly, the chest is not locked." << endl;
			if (nProbabilityItem <= 14)
			{
				cout << "You open the chest and you found the " << aWeapon[nProbabilityItem].wGetName() << "." << endl;
				cout << "Do you want to change it?" << endl;
				cout << "Yes/No?" << endl;
				string sChanging;
				if (sChanging == "Yes" || sChanging == "yes" || sChanging == "1" || sChanging == "true" || sChanging == "True")
				{
					player.SetWeapon(nProbabilityItem);
					weapon = aWeapon[nProbabilityItem];
				}
				else
				{
					cout << "You decided to leave the equipment behind." << endl;
				}
			}
			else if (nProbabilityItem >= 15 || nProbabilityItem <= 29)
			{
				cout << "You open the chest and you found the " << aArmor[nProbabilityItem].aGetName() << "." << endl;
				cout << "Do you want to change it?" << endl;
				cout << "Yes/No?" << endl;
				string sChanging;
				if (sChanging == "Yes" || sChanging == "yes" || sChanging == "1" || sChanging == "true" || sChanging == "True")
				{
					player.SetArmor(nProbabilityItem - 15);
					armor = aArmor[nProbabilityItem - 15];
				}
				else
				{
					cout << "You decided to leave the equipment behind." << endl;
				}
			}
			else
			{
				cout << "You open the chest and you found a potion." << endl;
				nPotion++;
			}
			cout << "You earn 20 EXP." << endl;
			player.Leveling(20);
			cout << "You also found a laying note near the chest." << endl;
			cout << "Apperantly the note is a treasure map." << endl;
			cout << "You decided to follow the map." << endl;
			ChoiceTwoOne();
		}
		else
		{
			cout << "You leave the chest alone." << endl;
			ChoiceTwoOne();
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
			ChoiceTwoOne();
		}
		else
		{
			cout << "Nothing around you interests you." << endl;
			cout << "You decided to enter the dungeon." << endl;
			ChoiceTwoOne();
		}
	}
}

void ChoiceTwo()
{
	cin.ignore();
	cout << "You are not interested with the bounty." << endl;
	cout << "Someone is calling you in the corner of the room." << endl;
	cout << "Would you answer its calling?" << endl;
	cout << "Yes/No" << endl;
	string sCalling;
	getline(cin, sCalling);
	if (sCalling == "Yes" || sCalling == "yes" || sCalling == "1" || sCalling == "true" || sCalling == "True")
	{
		cout << "You approached the man." << endl;
		cout << "He seems to be shaddy and a bit suspicious." << endl;
		cout << "He say that he would pay you to enter steal" << endl;
		cout << "a certain item from a ruin." << endl;
		cout << "Would you do it?" << endl;
		cout << "Yes/No?" << endl;
		string sYes;
		getline(cin, sYes);
		if (sYes == "Yes" || sYes == "yes" || sYes == "1" || sYes == "true" || sYes == "True")
		{

		}
		else
		{
			cout << "You decided to leave the pub." << endl;
			cout << "You left the town." << endl;
			ChoiceOneOne();
		}
	}
	else
	{
		cout << "You left the pub." << endl;
		cout << "You decided to left the city." << endl;
		ChoiceOneOne();
	}
	return;
}

void ChoiceTwoOne()
{
	srand(time(NULL));
	int nArea = 0;
	int nRoomCheck;
	int nProbabilityEvent;
	int nProbabilityItem;
	int nProbabilityEnemy;
	for (nRoomCheck = 0; nRoomCheck <= 50; nRoomCheck++)
	{
		nProbabilityEvent = rand() % 10 + 1;
		int nDirection = 0;
		cout << "Area: " << nArea << endl;
		cout << "Where are you going?" << endl;
		cout << "1. Forward" << endl;
		cout << "2. Right" << endl;
		cout << "3. Left" << endl;
		cout << "4. Backward" << endl;
		cin >> nDirection;
		switch (nDirection)
		{
		case 1:
			cout << "An enemy appeared!" << endl;
			if (nProbabilityEvent >= 1 || nProbabilityEvent <= 4)
			{
				nProbabilityEnemy = rand() % 20 + 1;

				if (nProbabilityEnemy > 0 || nProbabilityEnemy < 4)
				{
					BattleSystem(enemy[0], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 4 || nProbabilityEnemy <= 6)
				{
					BattleSystem(enemy[1], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 7 || nProbabilityEnemy <= 9)
				{
					BattleSystem(enemy[2], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 10 || nProbabilityEnemy <= 12)
				{
					BattleSystem(enemy[3], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 13 || nProbabilityEnemy <= 15)
				{
					BattleSystem(enemy[5], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 16 || nProbabilityEnemy <= 18)
				{
					BattleSystem(enemy[6], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 19 || nProbabilityEnemy <= 20)
				{
					BattleSystem(enemy[7], player, weapon, armor);
				}
			}
			else if (nProbabilityEvent >= 5 || nProbabilityEvent <= 7)
			{
				nProbabilityItem = rand() % 35 + 0;
				cout << "You found a chest!" << endl;
				if (nProbabilityItem <= 14)
				{
					cout << "You open the chest and you found the " << aWeapon[nProbabilityItem].wGetName() << "." << endl;
					cout << "Do you want to change it?" << endl;
					cout << "Yes/No?" << endl;
					string sChanging;
					if (sChanging == "Yes" || sChanging == "yes" || sChanging == "1" || sChanging == "true" || sChanging == "True")
					{
						player.SetWeapon(nProbabilityItem);
						weapon = aWeapon[nProbabilityItem];
					}
					else
					{
						cout << "You decided to leave the equipment behind." << endl;
					}
				}
				else if (nProbabilityItem >= 15 || nProbabilityItem <= 29)
				{
					cout << "You open the chest and you found the " << aArmor[nProbabilityItem].aGetName() << "." << endl;
					cout << "Do you want to change it?" << endl;
					cout << "Yes/No?" << endl;
					string sChanging;
					if (sChanging == "Yes" || sChanging == "yes" || sChanging == "1" || sChanging == "true" || sChanging == "True")
					{
						player.SetArmor(nProbabilityItem - 15);
						armor = aArmor[nProbabilityItem - 15];
					}
					else
					{
						cout << "You decided to leave the equipment behind." << endl;
					}
				}
				else
				{
					cout << "You open the chest and you found a potion." << endl;
					nPotion++;
				}
			}
			else
			{
				cout << "There is nothing here..." << endl;
			}
			break;
		case 2:
			cout << "An enemy appeared!" << endl;
			if (nProbabilityEvent >= 1 || nProbabilityEvent <= 4)
			{
				nProbabilityEnemy = rand() % 20 + 1;

				if (nProbabilityEnemy > 0 || nProbabilityEnemy < 4)
				{
					BattleSystem(enemy[0], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 4 || nProbabilityEnemy <= 6)
				{
					BattleSystem(enemy[1], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 7 || nProbabilityEnemy <= 9)
				{
					BattleSystem(enemy[2], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 10 || nProbabilityEnemy <= 12)
				{
					BattleSystem(enemy[3], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 13 || nProbabilityEnemy <= 15)
				{
					BattleSystem(enemy[5], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 16 || nProbabilityEnemy <= 18)
				{
					BattleSystem(enemy[6], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 19 || nProbabilityEnemy <= 20)
				{
					BattleSystem(enemy[7], player, weapon, armor);
				}
			}
			else if (nProbabilityEvent >= 5 || nProbabilityEvent <= 7)
			{
				nProbabilityItem = rand() % 35 + 0;
				cout << "You found a chest!" << endl;
				if (nProbabilityItem <= 14)
				{
					cout << "You open the chest and you found the " << aWeapon[nProbabilityItem].wGetName() << "." << endl;
					cout << "Do you want to change it?" << endl;
					cout << "Yes/No?" << endl;
					string sChanging;
					if (sChanging == "Yes" || sChanging == "yes" || sChanging == "1" || sChanging == "true" || sChanging == "True")
					{
						player.SetWeapon(nProbabilityItem);
						weapon = aWeapon[nProbabilityItem];
					}
					else
					{
						cout << "You decided to leave the equipment behind." << endl;
					}
				}
				else if (nProbabilityItem >= 15 || nProbabilityItem <= 29)
				{
					cout << "You open the chest and you found the " << aArmor[nProbabilityItem].aGetName() << "." << endl;
					cout << "Do you want to change it?" << endl;
					cout << "Yes/No?" << endl;
					string sChanging;
					if (sChanging == "Yes" || sChanging == "yes" || sChanging == "1" || sChanging == "true" || sChanging == "True")
					{
						player.SetArmor(nProbabilityItem - 15);
						armor = aArmor[nProbabilityItem - 15];
					}
					else
					{
						cout << "You decided to leave the equipment behind." << endl;
					}
				}
				else
				{
					cout << "You open the chest and you found a potion." << endl;
					nPotion++;
				}
			}
			else
			{
				cout << "There is nothing here..." << endl;
			}
			break;
		case 3:
			cout << "An enemy appeared!" << endl;
			if (nProbabilityEvent >= 1 || nProbabilityEvent <= 4)
			{
				nProbabilityEnemy = rand() % 20 + 1;

				if (nProbabilityEnemy > 0 || nProbabilityEnemy < 4)
				{
					BattleSystem(enemy[0], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 4 || nProbabilityEnemy <= 6)
				{
					BattleSystem(enemy[1], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 7 || nProbabilityEnemy <= 9)
				{
					BattleSystem(enemy[2], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 10 || nProbabilityEnemy <= 12)
				{
					BattleSystem(enemy[3], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 13 || nProbabilityEnemy <= 15)
				{
					BattleSystem(enemy[5], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 16 || nProbabilityEnemy <= 18)
				{
					BattleSystem(enemy[6], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 19 || nProbabilityEnemy <= 20)
				{
					BattleSystem(enemy[7], player, weapon, armor);
				}
			}
			else if (nProbabilityEvent >= 5 || nProbabilityEvent <= 7)
			{
				nProbabilityItem = rand() % 35 + 0;
				cout << "You found a chest!" << endl;
				if (nProbabilityItem <= 14)
				{
					cout << "You open the chest and you found the " << aWeapon[nProbabilityItem].wGetName() << "." << endl;
					cout << "Do you want to change it?" << endl;
					cout << "Yes/No?" << endl;
					string sChanging;
					if (sChanging == "Yes" || sChanging == "yes" || sChanging == "1" || sChanging == "true" || sChanging == "True")
					{
						player.SetWeapon(nProbabilityItem);
						weapon = aWeapon[nProbabilityItem];
					}
					else
					{
						cout << "You decided to leave the equipment behind." << endl;
					}
				}
				else if (nProbabilityItem >= 15 || nProbabilityItem <= 29)
				{
					cout << "You open the chest and you found the " << aArmor[nProbabilityItem].aGetName() << "." << endl;
					cout << "Do you want to change it?" << endl;
					cout << "Yes/No?" << endl;
					string sChanging;
					if (sChanging == "Yes" || sChanging == "yes" || sChanging == "1" || sChanging == "true" || sChanging == "True")
					{
						player.SetArmor(nProbabilityItem - 15);
						armor = aArmor[nProbabilityItem - 15];
					}
					else
					{
						cout << "You decided to leave the equipment behind." << endl;
					}
				}
				else
				{
					cout << "You open the chest and you found a potion." << endl;
					nPotion++;
				}
			}
			else
			{
				cout << "There is nothing here..." << endl;
			}
			break;
		default:
			cout << "An enemy appeared!" << endl;
			if (nProbabilityEvent >= 1 || nProbabilityEvent <= 4)
			{
				nProbabilityEnemy = rand() % 20 + 1;

				if (nProbabilityEnemy > 0 || nProbabilityEnemy < 4)
				{
					BattleSystem(enemy[0], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 4 || nProbabilityEnemy <= 6)
				{
					BattleSystem(enemy[1], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 7 || nProbabilityEnemy <= 9)
				{
					BattleSystem(enemy[2], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 10 || nProbabilityEnemy <= 12)
				{
					BattleSystem(enemy[3], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 13 || nProbabilityEnemy <= 15)
				{
					BattleSystem(enemy[5], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 16 || nProbabilityEnemy <= 18)
				{
					BattleSystem(enemy[6], player, weapon, armor);
				}

				if (nProbabilityEnemy >= 19 || nProbabilityEnemy <= 20)
				{
					BattleSystem(enemy[7], player, weapon, armor);
				}
			}
			else if (nProbabilityEvent >= 5 || nProbabilityEvent <= 7)
			{
				nProbabilityItem = rand() % 35 + 0;
				cout << "You found a chest!" << endl;
				if (nProbabilityItem <= 14)
				{
					cout << "You open the chest and you found the " << aWeapon[nProbabilityItem].wGetName() << "." << endl;
					cout << "Do you want to change it?" << endl;
					cout << "Yes/No?" << endl;
					string sChanging;
					if (nProbabilityItem <= 14)
					{
						cout << "You open the chest and you found the " << aWeapon[nProbabilityItem].wGetName() << "." << endl;
						cout << "Do you want to change it?" << endl;
						cout << "Yes/No?" << endl;
						string sChanging;
						if (sChanging == "Yes" || sChanging == "yes" || sChanging == "1" || sChanging == "true" || sChanging == "True")
						{
							player.SetWeapon(nProbabilityItem);
							weapon = aWeapon[nProbabilityItem];
						}
						else
						{
							cout << "You decided to leave the equipment behind." << endl;
						}
					}
					else if (nProbabilityItem >= 15 || nProbabilityItem <= 29)
					{
						cout << "You open the chest and you found the " << aArmor[nProbabilityItem].aGetName() << "." << endl;
						cout << "Do you want to change it?" << endl;
						cout << "Yes/No?" << endl;
						string sChanging;
						if (sChanging == "Yes" || sChanging == "yes" || sChanging == "1" || sChanging == "true" || sChanging == "True")
						player.SetArmor(nProbabilityItem - 15);
						armor = aArmor[nProbabilityItem - 15];
					}
					else
					{
						cout << "You decided to leave the equipment behind." << endl;
					}
				}
				else
				{
					cout << "You open the chest and you found a potion." << endl;
					nPotion++;
				}
			}
			else
			{
				cout << "There is nothing here..." << endl;
			}
			break;
		}
		nArea++;
	}	
}

void End()
{
	cout << "You have reached the end of the room." << endl;
	cout << "You saw a pedestal at the end of the room." << endl;
	cout << "There is something on top of the pedestal, something precious." << endl;
	cout << "However, something large descends from the sky." << endl;
	cout << "It was a dragon!" << endl;
	cout << "It starting to spew fire out of his snout." << endl;
	BattleSystem(enemy[9], player, weapon, armor);
	cout << "As you passed by the dead beast, you approached the object." << endl;
	cout << "You touch the object and it glows intensely." << endl;
	cout << "It was the chalice." << endl;
	cout << "You have succeed the game!" << endl;
	system("PAUSE");
	exit(0);
}