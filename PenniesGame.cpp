#include <iostream>
#include <string>
#include <time.h>
#include <ctype.h>
using namespace std;

void ManyPennies(int& penniesLeft)
{
  cout << "\nThere are now " << penniesLeft << " left" << endl;
  for (int i = 0; i < penniesLeft; i++)
  {
    cout << "O";
  }
  cout << "\n";
}

void main ()
{
  //Variables
  bool gameActive = true; //runs the game
  string viewRules; //user inputted character for rules response (Y/N)
  int numberOfGames = 5; // number of games that the user can play
  int firstPlayer = 1; //the player who goes first
  bool playersTurn; //when true, is the player's turn
  int penniesLeft = 30; //number of pennies left in game
  int userTakeaway = '\0'; //the amount of pennies the user takes away
  int computerTakeaway = '\0'; //the amount the computer takes away
  int winComputer = 0; //number of wins by computer
  int winPlayer = 0; //number of wins by player
  int numberOfTurns = 0; //number of turns
  char userKey = '\0'; //used when user inputs a (random) character to continue
  srand(time(NULL)); //sets 'random' string to use current time



  while (gameActive = true)
  { //Introduction
    cout << "Welcome to the Pennies Game! \n " << endl;
    cout << "Would you like to view the rules? (Y/N)" << endl;
    cin >> viewRules; //user inputs Y or N

    if (viewRules == "Y" || viewRules == "y") //if 'Y' is pressed, rules shown
    { //Rules are displayed here:
      cout << "\nRules:\n1)You will play 5 games against a computer.\n";
      cout << "\n2)You will take away 1 - 5 coins per turn,";
      cout << " with the number of coins shown onscreen.\n";
      cout << "\n3)Whoever takes the last penny loses." << endl;
    }//if ends

    else if (viewRules == "N" || viewRules == "n") //shown if 'N' is pressed:
    {
      cout << "\nBrilliant! Let's get started!" << endl;
    }//else if ends

    else //shown if neither 'Y' or 'N' are inputted
    {
      cout << "Please enter Y or N:" << endl;
      cin >> viewRules; //user 
    }//else ends

    //Who plays first
    if (firstPlayer == 1) //default - if the value is set to 1 in the code,
      //then the player goes first
    {
      cout << "You'll go first!\n" << endl;
      playersTurn = true;
    }

    if (firstPlayer == 2) //if the value is set to 2
    {
      cout << "\nThe computer goes first!\n" << endl;
      playersTurn = false;
    }//closes if 

    if (firstPlayer <= 0 || firstPlayer >= 3)//if the value is not 1 or 2
    {
      cout << "\nPlease check the variable in the code: ";
      cin >> firstPlayer; //user must input another value
    }//close if

    //Turns

    while (numberOfGames > 0) // loop run while the player has more than 0 games to play
    {
      //Player's Turn - everything here is run when it is the player's go
      while ((playersTurn == true))
      {
        if ((penniesLeft > 1)) //if there is over one penny left
        {
          cout << "\nIt's your turn!" << endl;
          cout << "How many pennies would you like to take away?" << endl;
          cin >> userTakeaway; //the player inputs a number
          if (!isdigit || userTakeaway < 1 || userTakeaway > 5)
          {

              cout << "Please input a number between 1 and 5" << endl;
              cin >> userTakeaway;

          }
          penniesLeft = penniesLeft - userTakeaway; //pennies are taken away
          ManyPennies(penniesLeft); //calls subprogram to print how many pennies are left
          numberOfTurns++; //adds to number of turns

          //cout << "Press any key to continue...\n" << endl;
          //cin >> userKey;
        }
        else if ((penniesLeft == 1))
        {
          cout << "There is a single penny left..." << endl;
          cout << "...you pick it up...";
          cin >> userKey;

          cout << "\nThe computer wins this game in ";
          cout << numberOfTurns << " turns!" << endl;
          winComputer++;
          --numberOfGames;

          cout << "\nThe current score is - ";
          cout << "\nPlayer: " << winPlayer << " Computer: ";
          cout << winComputer << endl;

          cout << "You have " << numberOfGames << " remaining!" << endl;
          penniesLeft = 30;
          numberOfTurns = 0;
          computerTakeaway = 0;
          userTakeaway = 0;

          //cout << "Press any key to continue..." << endl;
          //cin >> userKey;
        }
        else if ((penniesLeft == 0))
        {
          cout << "\nThe computer wins this game in ";
          cout << numberOfTurns << " turns!" << endl;
          winComputer++;
          --numberOfGames;

          cout << "\nThe current score is - ";
          cout << "\nPlayer: " << winPlayer << " Computer: ";
          cout << winComputer << endl;

          cout << "You have " << numberOfGames << " games remaining!" << endl;
          penniesLeft = 30;
          numberOfTurns = 0;
          computerTakeaway = 0;
          userTakeaway = 0;

          cout << "Press any key to continue..." << endl;
          cin >> userKey;

        }
        playersTurn = false;
        break;
      }//player turn loop ends here

      while ((!playersTurn))
      {
        if ((penniesLeft >= 7))
        {
          cout << "\nIt's the computer's turn!" << endl;
          penniesLeft = penniesLeft - (computerTakeaway = rand() % 5 + 1);

          cout << "The computer has taken away " << computerTakeaway;
          cout << " pennies!" << endl;
          ManyPennies (penniesLeft);
          numberOfTurns++;
        }

        else if ((penniesLeft >= 2 && penniesLeft <= 6))
        {
          cout << "\nIt's the computer's turn!\n" << endl;
          penniesLeft = penniesLeft - (computerTakeaway = --penniesLeft);
          cout << "The computer has taken away " << computerTakeaway;
          cout << " pennies!" << endl;
          ManyPennies(penniesLeft);
          numberOfTurns++;
          playersTurn = false;

          cout << "Press any key to continue..." << endl;
          cin >> userKey;
        }

        else if ((penniesLeft == 1))
        {
          cout << "\nThe computer calculates that one penny remains..." << endl;
          cout << "\nYou win the round in ";
          cout << numberOfTurns << " turns!" << endl;
          winPlayer++;
          --numberOfGames;

          cout << "The current score is - ";
          cout << "\nPlayer: " << winPlayer << " Computer: ";
          cout << winComputer << endl;

          cout << "You have " << numberOfGames << " games remaining!" << endl;
          penniesLeft = 30;
          numberOfTurns = 0;
          computerTakeaway = 0;
          userTakeaway = 0;

          cout << "\nPress any key to continue..." << endl;
          cin >> userKey;
        }

        else if ((penniesLeft == 0 ))
        {
          cout << "You win the round in ";
          cout << numberOfTurns << " turns!" << endl;
          winPlayer++;
          --numberOfGames;

          cout << "\nThe current score is - ";
          cout << "\nPlayer: " << winPlayer << " Computer: ";
          cout << winComputer << endl;

          cout << "You have " << numberOfGames << " games remaining!" << endl;
          penniesLeft = 30;
          numberOfTurns = 0;
          computerTakeaway = 0;
          userTakeaway = 0;
        }

        playersTurn = true;
        break;
      }
    } //while games > 0 loop end


  }//game active loop ends
}//program ends
