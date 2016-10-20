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

struct Weapon
{
	int nHealth = 0;
	int nMana = 0;
	int nAttack = 0;
	int nDefence = 0;
	int nMagicAttack = 0;
	int nMagicDefence = 0;
	int nAgility = 0;
	int nLuck = 0;
};

//Initializing structure for Weapon

struct Armor
{
	int nHealth = 0;
	int nMana = 0;
	int nAttack = 0;
	int nDefence = 0;
	int nMagicAttack = 0;
	int nMagicDefence = 0;
	int nAgility = 0;
	int nLuck = 0;
};

//Initializing structure for the player

struct Player
{
public:
	string sPlayerName;
	int nHealth = 0;
	int nMana = 0;
	int nCurrency = 500;
	int nJob;
	int nRace;
	int nlevel = 1;
	int nEXP = 0;
	int nAttack = 0;
	int nDefence = 0;
	int nMagicAttack = 0;
	int nMagicDefence = 0;
	int nAgility = 0;
	int nLuck = 0;
};

//Initializing structure for enemies

struct Enemies
{
	int nHealth = 0;
	int nMana = 0;
	int nAttack = 0;
	int nDefence = 0;
	int nMagicAttack = 0;
	int nMagicDefence = 0;
	int nAgility = 0;
	int nLuck = 0;
};

//Function prototypes

void PlayerCreation();
void Story();
void ChoiceOne();
void ChoiceOneOne();
void ChoiceTwo();

//Function to create the player

void PlayerCreation()
{
	Player player;
	cout << "Welcome to the your Simple Adventure!" << endl;
	cout << "Before we continue, can you please tell your name?" << endl;
	cin >> player.sPlayerName;
	cout << "What are you?" << endl;
	cout << "1.Human" << setw(10) << "2.Elf" << setw(10) << "3.Dwarf" << setw(10) << "4.Orc" << setw(15) << "5.Halfling" << endl;
	cout << "Enter 1-5." << endl;
	cin >> player.nRace;
	if (player.nRace < 1 || player.nRace > 5)
	{
		cout << "Race not found, exiting game...";
		return;
	}
	else if (player.nRace == 1)
	{
		cout << player.sPlayerName << " the human." << endl;
		player.nHealth += 100;
		player.nMana += 50;
		player.nAttack += 5;
		player.nDefence += 5;
		player.nMagicAttack += 5;
		player.nMagicDefence += 5;
		player.nAgility += 5;
		player.nLuck += 5;
		cout << "Health: " << player.nHealth << "\nMana: " << player.nMana << "\nAttack: " << player.nAttack << "\nDefence: " << player.nDefence << "\nMagicAttack: " << player.nMagicAttack << "\nMagicDefence: " << player.nMagicDefence << "\nAgility: " << player.nAgility << "\nLuck: " << player.nLuck << endl;
	}
	else if (player.nRace == 2)
	{
		cout << player.sPlayerName << " the elf." << endl;
		player.nHealth += 70;
		player.nMana += 120;
		player.nAttack += 2;
		player.nDefence += 2;
		player.nMagicAttack += 8;
		player.nMagicDefence += 8;
		player.nAgility += 7;
		player.nLuck += 6;
		cout << "Health: " << player.nHealth << "\nMana: " << player.nMana << "\nAttack: " << player.nAttack << "\nDefence: " << player.nDefence << "\nMagicAttack: " << player.nMagicAttack << "\nMagicDefence: " << player.nMagicDefence << "\nAgility: " << player.nAgility << "\nLuck: " << player.nLuck << endl;
	}
	else if (player.nRace == 3)
	{
		cout << player.sPlayerName << " the dwarf." << endl;
		player.nHealth += 120;
		player.nMana += 40;
		player.nAttack += 7;
		player.nDefence += 5;
		player.nMagicAttack += 3;
		player.nMagicDefence += 2;
		player.nAgility += 4;
		player.nLuck += 8;
		cout << "Health: " << player.nHealth << "\nMana: " << player.nMana << "\nAttack: " << player.nAttack << "\nDefence: " << player.nDefence << "\nMagicAttack: " << player.nMagicAttack << "\nMagicDefence: " << player.nMagicDefence << "\nAgility: " << player.nAgility << "\nLuck: " << player.nLuck << endl;
	}
	else if (player.nRace == 4)
	{
		cout << player.sPlayerName << " the orc." << endl;
		player.nHealth += 150;
		player.nMana += 20;
		player.nAttack += 10;
		player.nDefence += 8;
		player.nMagicAttack += 1;
		player.nMagicDefence += 2;
		player.nAgility += 6;
		player.nLuck += 3;
		cout << "Health: " << player.nHealth << "\nMana: " << player.nMana << "\nAttack: " << player.nAttack << "\nDefence: " << player.nDefence << "\nMagicAttack: " << player.nMagicAttack << "\nMagicDefence: " << player.nMagicDefence << "\nAgility: " << player.nAgility << "\nLuck: " << player.nLuck << endl;
	}
	else
	{
		cout << player.sPlayerName << " the halfling." << endl;
		player.nHealth += 50;
		player.nMana += 80;
		player.nAttack += 6;
		player.nDefence += 3;
		player.nMagicAttack += 4;
		player.nMagicDefence += 6;
		player.nAgility += 10;
		player.nLuck += 7;
		cout << "Health: " << player.nHealth << "\nMana: " << player.nMana << "\nAttack: " << player.nAttack << "\nDefence: " << player.nDefence << "\nMagicAttack: " << player.nMagicAttack << "\nMagicDefence: " << player.nMagicDefence << "\nAgility: " << player.nAgility << "\nLuck: " << player.nLuck << endl;
	}
	cout << "What is your job?" << endl;
	cout << "1.Knight" << setw(10) << "2.Mage" << setw(15) << "3.Mechanic" << setw(10) << "4.Thief" << setw(10) << "5.Noble" << endl;
	cout << "Enter 1-5." << endl;
	cin >> player.nJob;
	if (player.nJob < 1 || player.nJob > 5)
	{
		cout << "Job not found, you are fired!";
		return;
	}
	else if (player.nJob == 1)
	{
		cout << player.sPlayerName << " the knight." << endl;
		player.nHealth += 50;
		player.nMana += 10;
		player.nAttack += 3;
		player.nDefence += 3;
		player.nMagicAttack += 1;
		player.nMagicDefence += 1;
		player.nAgility -= 2;
		player.nLuck += 0;
		cout << "Health: " << player.nHealth << "\nMana: " << player.nMana << "\nAttack: " << player.nAttack << "\nDefence: " << player.nDefence << "\nMagicAttack: " << player.nMagicAttack << "\nMagicDefence: " << player.nMagicDefence << "\nAgility: " << player.nAgility << "\nLuck: " << player.nLuck << endl;
	}
	else if (player.nJob == 2)
	{
		cout << player.sPlayerName << " the mage." << endl;
		player.nHealth += 10;
		player.nMana += 50;
		player.nAttack -= 2;
		player.nDefence -= 2;
		player.nMagicAttack += 3;
		player.nMagicDefence += 3;
		player.nAgility += 0;
		player.nLuck += 2;
		cout << "Health: " << player.nHealth << "\nMana: " << player.nMana << "\nAttack: " << player.nAttack << "\nDefence: " << player.nDefence << "\nMagicAttack: " << player.nMagicAttack << "\nMagicDefence: " << player.nMagicDefence << "\nAgility: " << player.nAgility << "\nLuck: " << player.nLuck << endl;
	}
	else if (player.nJob == 3)
	{
		cout << player.sPlayerName << " the mechanic." << endl;
		player.nHealth += 30;
		player.nMana += 30;
		player.nAttack += 1;
		player.nDefence += 2;
		player.nMagicAttack += 1;
		player.nMagicDefence += 2;
		player.nAgility -= 3;
		player.nLuck -= 1;
		cout << "Health: " << player.nHealth << "\nMana: " << player.nMana << "\nAttack: " << player.nAttack << "\nDefence: " << player.nDefence << "\nMagicAttack: " << player.nMagicAttack << "\nMagicDefence: " << player.nMagicDefence << "\nAgility: " << player.nAgility << "\nLuck: " << player.nLuck << endl;
	}
	else if (player.nJob == 4)
	{
		cout << player.sPlayerName << " the thief." << endl;
		player.nHealth += 10;
		player.nMana += 40;
		player.nAttack += 2;
		player.nDefence -= 2;
		player.nMagicAttack += 1;
		player.nMagicDefence -= 3;
		player.nAgility += 3;
		player.nLuck += 3;
		cout << "Health: " << player.nHealth << "\nMana: " << player.nMana << "\nAttack: " << player.nAttack << "\nDefence: " << player.nDefence << "\nMagicAttack: " << player.nMagicAttack << "\nMagicDefence: " << player.nMagicDefence << "\nAgility: " << player.nAgility << "\nLuck: " << player.nLuck << endl;
	}
	else
	{
		cout << player.sPlayerName << " the noble." << endl;
		player.nHealth += 25;
		player.nMana += 40;
		player.nAttack += 1;
		player.nDefence += 1;
		player.nMagicAttack += 1;
		player.nMagicDefence += 1;
		player.nAgility -= 3;
		player.nLuck += 1;
		cout << "Health: " << player.nHealth << "\nMana: " << player.nMana << "\nAttack: " << player.nAttack << "\nDefence: " << player.nDefence << "\nMagicAttack: " << player.nMagicAttack << "\nMagicDefence: " << player.nMagicDefence << "\nAgility: " << player.nAgility << "\nLuck: " << player.nLuck << endl;
	}
	cout << "Good luck on your adventure," << player.sPlayerName << endl << endl;
	return;
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
	cout << "Enter 1-2." << endl;
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
			cout << "Enter 1-2." << endl;
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
		cin.get();
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
					break;
				default:
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
				cout << "You also found a now laying near the chest." << endl;
				cin.get();
			}
			else
			{
				cout << "You leave the chest alone." << endl;
				cin.get();
			}
			break;
		default:
			cout << "You are not sure what to do because you can't input the number 1 or 2." << endl;
			cout << "You wander off and ended up right front of the entrance of a dungeon." << endl;
			cout << "Would you go in?" << endl;
			string sEnteringDungeon;
			getline(cin, sEnteringDungeon);
			if (sEnteringDungeon == "Yes" || sEnteringDungeon == "yes" || sEnteringDungeon == "1" || sEnteringDungeon == "true" || sEnteringDungeon == "True")
			{
				cout << "You took the bounty." << endl;
				cout << "Your first clue is to head out of the city's wall." << endl;
				ChoiceOneOne();
				cin.get();
			}
			else
			{
				ChoiceTwo();
			}
	}
}

void ChoiceTwo()
{
	cout << "You are not interested with the bounty." << endl;
	cout << "Someone is calling you in the corner of the room." << endl;
	cout << "Would you answer his call?" << endl;
	string sCalling;
	getline(cin, sCalling);
	if (sCalling == "Yes" || sCalling == "yes" || sCalling == "1" || sCalling == "true" || sCalling == "True")
	{
		cout << "You approached the man." << endl;
		cout << "He seems to be shaddy and a bit suspicious." << endl;
		cout << "He say that he would pay you to enter steal an item from a ruin." << endl;
		cin.get();
	}
	else
	{
		cout << "You left the pub." << endl;
		cout << "You decided to left the city." << endl;
		ChoiceOneOne();
		cin.get();
	}
}



int main()
{
	srand(time(NULL));
	PlayerCreation();
	Story();
	return 0;
}
