// hangman.cpp
// Hangman game illustrates string library functions, 
// character arrays, arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Prototype. we'll define this below.
int processGuess(char* word, const char* targetWord, char guess);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s
const char* wordBank[] = {"computer", "president", "trojan", "program",
                          "coffee", "library", "football", "popcorn", 
                          "science", "engineer"};

const int numWords = 10;

int main()
{
  srand(time(0));
  char guess;
  bool wordGuessed = false;
  int numTurns = 10;

  // Pick a random word from the wordBank
  const char* targetWord = wordBank[rand() % numWords];
  // More initialization code as needed
  char word[80];

  for (int i = 0; i < strlen(targetWord); i++) //fills array with num of stars = num of word
  {
    word[i] = '*';
  }
  word[strlen(targetWord)] = '\0';  

  // An individual game continues until a word
  // is guessed correctly or 10 turns have elapse

  while (wordGuessed == false && numTurns != 0) 
  {

    cout << "Current Word: ";
    for (int i=0; i<strlen(targetWord); i++)
    {
      cout << word[i];
    }
    cout << endl << numTurns << " remain... Enter a letter to guess: " << endl;
    cin >> guess;

    //int r = processGuess(word, targetWord, guess);

    if (processGuess(word, targetWord, guess) == 0) //none correct
    { 
      numTurns--;
    }
   
    if (strcmp(word, targetWord) == 0) //if word = target
    {
      wordGuessed = true;
    }

  }

  // Print out end of game status
  if(wordGuessed == true)
  {
     cout << "The word was: " << targetWord << "." << " You win!" << endl; 
  }

  else if(numTurns == 0)
  {
    cout << "Too many turns... You lose!" << endl; 
  }
 
  return 0;
}

// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
int processGuess(char* word, const char* targetWord, char guess)
{
  int correct = 0; 
  int i = 0;
  while (targetWord[i] != '\0')
  {
    if (targetWord[i] == guess)
    {
      word[i] = guess;
      correct++;
    }
    
     i++;
  }

  return correct;
}
