/*******************************************************************************
 * CS 103 Twenty-One (Blackjack) PA
 * Name: Samuel Lee
 * USC email: lee344@usc.edu
 * Comments (you want us to know): This program simulates a game of black jack
 ******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

/* Prototypes */
void shuffle(int cards[]);
void printCard(int id);
int cardValue(int id);
void printHand(int hand[], int numCards);
int getBestScore(int hand[], int numCards);

//const int NUM_CARDS = 52;

/**
 * Global arrays to be used as look-up tables, if desired.
 * It is up to you if and how you want to use these 
 */

const char suit[4] = {'H','S','D','C'};
const char* type[13] = 
  {"2","3","4","5","6","7",
   "8","9","10","J","Q","K","A"};

/**
 * Should permute the deck of cards, effectively shuffling it.
 * You must use the Fisher-Yates / Durstenfeld shuffle algorithm
 *  described in the assignment writeup.
 */
void shuffle(int cards[])
{
  for (int i = 0; i < 52; i++) //reinitialize
  {
    cards[i] = i;
  }
  
  for (int i = 51 ; i > 0; i--) // shuffle deck
  {
    int j = rand()%(i+1);
    int temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
  }

}

/*
 * Prints the card in a "pretty" format:   "type-suit"
 *  Examples:  K-C  (King of clubs), 2-H (2 of hearts)
 *  Valid Types are: 2,3,4,5,6,7,8,9,10,J,Q,K,A
 *  Valid Suits are: H, D, C, S
 */
void printCard(int id)
{
  //Type
  if (id >= 0 && id <= 12) //if the id between a certain range then...
  {
    cout << type[id] << "-";
  }

  else if (id >= 13 && id <= 25) //if in another range then...
  {
    cout << type[id-13] << "-";
  }

  else if (id >= 26 && id <= 38)
  {
    cout << type[id-26] << "-";
  }

  else if (id >= 39 && id <= 51)
  {
    cout << type[id-39] << "-";
  }

  //Suit 
  if (id >= 0 && id <= 12) //if id is between a certain range then...
  {
    cout << suit[0];
  }

  else if (id >= 13 && id <= 25) //if in another range then...
  {
    cout << suit[1];
  }

  else if (id >= 26 && id <= 38)
  {
    cout << suit[2];
  }

  else if (id >= 39 && id <= 51)
  {
    cout << suit[3];
  }
}

/**
 * Returns the numeric value of the card.
 *  Should return 11 for an ACE and can then
 *  be adjusted externally based on the sum of the score.
 */
int cardValue(int id)
{
  int value; 

  if (id >= 0 && id <= 8) //if id in a certain range then value = ...
  {
    value = id + 2; 
  }

  else if (id >= 13 && id <= 21)
  {
    value = id - 11; 
  }

  else if (id >= 26 && id <= 34)
  {
    value = id - 24; 
  }

  else if (id >= 39 && id <= 47)
  {
    value = id - 37; 
  }

  else if ((id >= 9 && id <= 11) || (id >= 22 && id <= 24) || 
          (id >= 35 && id <= 37) || (id >= 48 && id <= 50))
  {
    value = 10; 
  }

  else //ace 
  { 
    value = 11;
  }

return value;
}

/**
 * Should print out each card in the hand separated by a space and
 * then print a newline at the end.  
 * Should use printCard() to print out each card.
 */
void printHand(int hand[], int numCards)
{
  for (int i = 0; i < numCards; i++) //print until i < numCards
  {
    printCard(hand[i]);
    cout << " ";  
  }
  cout << endl;
}

/**
 * Should return the total score of the provided hand.  
 * ACES should be treated as 11s to make the highest possible hand
 *  and only being reduced to 1s as needed to avoid busting.
 */
int getBestScore(int hand[], int numCards)
{
  /******** You complete ****************/
  int total = 0;
  int numAce = 0;

  for (int i = 0; i < numCards; i++)
  {
      total += cardValue(hand[i]); //calculate the total
      
      if (cardValue(hand[i]) == 11) //check if any aces are in hand
      {
        numAce++; 
      }
  }

  if ((total > 21) && (numAce > 0)) //bust and more than or equal to one ace
  {
  
    while (total > 21 && numAce != 0) //change value of ace to 1
    {
      total -= 10;
      numAce--;
    }

    return total; 
  }

  else 
  {
    return total;
  }
}


/* Main program logic for the game of 21 */
int main(int argc, char* argv[])
{
  //---------------------------------------
  // Do not change this code -- Begin
  //---------------------------------------
  if(argc < 2)
  {
    cout << "Error - Please provide the seed value." << endl;
    return 1;
  }
  int seed = atoi(argv[1]);
  srand(seed);


  int cards[52];
  int dhand[9];
  int phand[9];
  //--------------------------------------
  // Do not change this code -- End
  //---------------------------------------

  /******** You complete ****************/

  char playagain = 'y'; 

  while (playagain == 'y') //while loop to check if user wants to play again
  {
    /*****Declar Variables****/
    char choice; //choice for h or stand
    bool gameEnd = false; // boolean for game ending
    bool pBlackjack = false; //boolean for player black jack


    shuffle(cards);

    /*******Deal Cards*******/
    phand[0] = cards[0]; //first and third cards to player
    phand[1] = cards[2]; 

    dhand[0] = cards[1]; //second and fourth cards to dealer
    dhand[1] = cards[3];

    cout << "Dealer Hand: " << "? "; //conceal dealer's first card
    printCard(dhand[1]);  //present second card
    cout << endl;

    cout << "Player Hand: "; //present players hand.
    printCard(phand[0]); 
    cout << " ";
    printCard(phand[1]); 
    cout << endl;

    /*********Begin Game*********/

    if (getBestScore(phand, 2) == 21) //if player gets 21 right away
    {

      int i = 2; //counter for num of dealer's cards
      while (getBestScore(dhand, i) < 17) //deal while dhand less than 17
      {  	
      	dhand[i] = cards[i+2];
        i++;
      }

      if (getBestScore(dhand, i) > 21) //if dealer bust
      {
        cout << "Dealer: " << endl;
        printHand(dhand, i);

        cout << "Dealer Busts " << endl;
        cout << "Win " << getBestScore(phand, 2); 
        cout << " " << getBestScore(dhand, i);
      }

      else if (getBestScore(dhand, i) < 21) //if player win by score
      {
      	cout << "Dealer: "; 
        printHand(dhand, i);

        cout << "Win ";
        cout << getBestScore(phand, 2); 
        cout << " " << getBestScore(dhand, i) << endl;
      }

      else //dealer also 21
      {
      	cout << "Dealer: "; 
      	printHand(dhand, i);

      	cout << "Tie"; 
      	cout << getBestScore(phand, 2);
        cout << " " << getBestScore(dhand, i) << endl;
      }
    }

    else //player does not blackjack with first two cards
    {
    	int j = 2; //next open index in array phand
    	int m = 2; //next open index in array dhand
		int k = 4; //next index in array cards

    	while (gameEnd == false)
    	{
       		
          if (pBlackjack == false) //if player doesnt bj, prompt choice
          {
            cout << "Type 'h' to hit and 's' to stay: " << endl;
            cin >> choice; 
          }

          else //if they black jack then automaticall stand
          {
            choice = 's';
          }

    		if (choice == 'h') //player hits
    		{
    			phand[j] = cards[k]; //deal card to player
          
          		 j++; //update next open array
         		 k++; //update next open array

    			cout << "Player: ";
    			printHand(phand, j); //print hand

    			if (getBestScore(phand, j) == 21) //player gets a black jack.
    			{
    				pBlackjack = true;
    			}

    			if (getBestScore(phand, j) > 21) //player busts
    			{ 
    				cout << "Player busts" << endl;

    				cout << "Lose ";
    				cout << getBestScore(phand, j);
            		cout << " " << getBestScore(dhand, 2) << endl;
    				gameEnd = true;
    			}
    		}

    		else if (choice == 's') //player stays
    		{
    			while (getBestScore(dhand, m) < 17) //deal while less thant 17
    			{
      				dhand[m] = cards[k];
        			m++;
        			k++;
    			}

    			cout << "Dealer: ";
    			printHand(dhand, m);

    			if (getBestScore(dhand, m) > 21) //dealer busts
    			{
       				cout << "Dealer Busts " << endl;

        			cout << "Win " << getBestScore(phand, j); 
              		cout << " " << getBestScore(dhand, m) << endl;
        			gameEnd = true;

    			}

    			else if(getBestScore(dhand, m) < getBestScore(phand, j)) //win
    			{
    				cout << "Win " << getBestScore(phand, j); 
            		cout << " " << getBestScore(dhand, m) << endl;
        			gameEnd = true;
    			}

    			else if(getBestScore(dhand, m) > getBestScore(phand, j)) //lose
    			{
    				cout << "Lose " << getBestScore(phand, j); 
           			cout << " " << getBestScore(dhand, m) << endl;
        			gameEnd = true;
    			}

    			else if(getBestScore(dhand, m) == getBestScore(phand, j)) //tie
    			{
    				cout << "Tie " << getBestScore(phand, j);
            		cout << " " << getBestScore(dhand, m) << endl;
        			gameEnd = true;
    			}
    		}

    		else //player types something else
    		{
    			return 0;
    		}

    	}
    }

  /****Play again???****/

	cout << endl << "Play again? [y/n]" << endl; //playagain?
	cin >> playagain; 

	}

  return 0;
}