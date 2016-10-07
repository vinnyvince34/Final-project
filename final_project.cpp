/*Vincent Alexander Seliang
 *CS02
 *2001585562*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <ctime>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;


class Player 
{
    public:
        string sPlayerName;
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

void PlayerCreation ()
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
        player.nAttack += 5;
        player.nDefence += 5;
        player.nMagicAttack += 5;
        player.nMagicDefence += 5;
        player.nAgility += 5;
        player.nLuck += 5;
        cout << "Attack: " << player.nAttack << "\nDefence: " << player.nDefence << "\nMagicAttack: " << player.nMagicAttack << "\nMagicDefence: " << player.nMagicDefence << "\nAgility: " << player.nAgility << "\nLuck: " << player.nLuck << endl;
    }
    else if (player.nRace == 2)
    {
        cout << player.sPlayerName << " the elf." << endl;
        player.nAttack += 2;
        player.nDefence += 2;
        player.nMagicAttack += 8;
        player.nMagicDefence += 8;
        player.nAgility += 7;
        player.nLuck += 6;
        cout << "Attack: " << player.nAttack << "\nDefence: " << player.nDefence << "\nMagicAttack: " << player.nMagicAttack << "\nMagicDefence: " << player.nMagicDefence << "\nAgility: " << player.nAgility << "\nLuck: " << player.nLuck << endl;
    }
    else if (player.nRace == 3)
    {
        cout << player.sPlayerName << " the dwarf." << endl;
        player.nAttack += 7;
        player.nDefence += 5;
        player.nMagicAttack += 3;
        player.nMagicDefence += 2;
        player.nAgility += 4;
        player.nLuck += 8;
        cout << "Attack: " << player.nAttack << "\nDefence: " << player.nDefence << "\nMagicAttack: " << player.nMagicAttack << "\nMagicDefence: " << player.nMagicDefence << "\nAgility: " << player.nAgility << "\nLuck: " << player.nLuck << endl;
    }
    else if (player.nRace == 4)
    {
        cout << player.sPlayerName << " the orc." << endl;
        player.nAttack += 10;
        player.nDefence += 8;
        player.nMagicAttack += 1;
        player.nMagicDefence += 2;
        player.nAgility += 6;
        player.nLuck += 3;
        cout << "Attack: " << player.nAttack << "\nDefence: " << player.nDefence << "\nMagicAttack: " << player.nMagicAttack << "\nMagicDefence: " << player.nMagicDefence << "\nAgility: " << player.nAgility << "\nLuck: " << player.nLuck << endl;
    }
    else
    {
        cout << player.sPlayerName << " the halfling." << endl;
        player.nAttack += 6;
        player.nDefence += 3;
        player.nMagicAttack += 4;
        player.nMagicDefence += 6;
        player.nAgility += 10;
        player.nLuck += 7;
        cout << "Attack: " << player.nAttack << "\nDefence: " << player.nDefence << "\nMagicAttack: " << player.nMagicAttack << "\nMagicDefence: " << player.nMagicDefence << "\nAgility: " << player.nAgility << "\nLuck: " << player.nLuck << endl;
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
        player.nAttack += 3;
        player.nDefence += 3;
        player.nMagicAttack += 1;
        player.nMagicDefence += 1;
        player.nAgility -= 2;
        player.nLuck += 0;
        cout << "Attack: " << player.nAttack << "\nDefence: " << player.nDefence << "\nMagicAttack: " << player.nMagicAttack << "\nMagicDefence: " << player.nMagicDefence << "\nAgility: " << player.nAgility << "\nLuck: " << player.nLuck << endl;
    }
    else if (player.nJob == 2)
    {
        cout << player.sPlayerName << " the mage." << endl;
        player.nAttack -= 2;
        player.nDefence -= 2;
        player.nMagicAttack += 3;
        player.nMagicDefence += 3;
        player.nAgility += 0;
        player.nLuck += 2;
        cout << "Attack: " << player.nAttack << "\nDefence: " << player.nDefence << "\nMagicAttack: " << player.nMagicAttack << "\nMagicDefence: " << player.nMagicDefence << "\nAgility: " << player.nAgility << "\nLuck: " << player.nLuck << endl;
    }
    else if (player.nJob == 3)
    {
        cout << player.sPlayerName << " the mechanic." << endl;
        player.nAttack += 1;
        player.nDefence += 2;
        player.nMagicAttack += 1;
        player.nMagicDefence += 2;
        player.nAgility -= 3;
        player.nLuck -= 1;
        cout << "Attack: " << player.nAttack << "\nDefence: " << player.nDefence << "\nMagicAttack: " << player.nMagicAttack << "\nMagicDefence: " << player.nMagicDefence << "\nAgility: " << player.nAgility << "\nLuck: " << player.nLuck << endl;
    }
    else if (player.nJob == 4)
    {
        cout << player.sPlayerName << " the thief." << endl;
        player.nAttack += 2;
        player.nDefence -= 2;
        player.nMagicAttack += 1;
        player.nMagicDefence -= 3;
        player.nAgility += 3;
        player.nLuck += 3;
        cout << "Attack: " << player.nAttack << "\nDefence: " << player.nDefence << "\nMagicAttack: " << player.nMagicAttack << "\nMagicDefence: " << player.nMagicDefence << "\nAgility: " << player.nAgility << "\nLuck: " << player.nLuck << endl;
    }
    else
    {
        cout << player.sPlayerName << " the noble." << endl;
        player.nAttack += 1;
        player.nDefence += 1;
        player.nMagicAttack += 1;
        player.nMagicDefence += 1;
        player.nAgility -= 3;
        player.nLuck += 1;
        cout << "Attack: " << player.nAttack << "\nDefence: " << player.nDefence << "\nMagicAttack: " << player.nMagicAttack << "\nMagicDefence: " << player.nMagicDefence << "\nAgility: " << player.nAgility << "\nLuck: " << player.nLuck << endl;
    }
    cout << "Good luck on your adventure," << player.sPlayerName << endl << endl;
    return;
}

void ChoiceTwo ()
{
    cout << "You are not interested with the bounty." << endl;
    cout << "Someone is calling you in the corner of the room." << endl;
    cout << "Would you answer his call?" << endl;
    string sCalling;
    if (sCalling == "Yes" || sCalling == "yes" || sCalling == "1" || sCalling == "true" || sCalling == "True")
    {
        cout << "You approached the man." << endl;
        cout << "He seems to be shaddy and a bit suspicious." << endl;
   }
    else
    {
        cout << "You left the pub." << endl;
    }
}

void ChoiceOne ()
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
    }
    else
    {
        ChoiceTwo ();
    }
}

void StoryOpening ()
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
        ChoiceOne ();
    }
    else
    {
        ChoiceTwo ();
    }
}

int main ()
{
    srand (time(NULL));
    PlayerCreation ();
    StoryOpening ();
    return 0;
}