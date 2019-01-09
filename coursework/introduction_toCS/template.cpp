******************************COMMAND LINE ARGUMENTS************
int main (int argc, char* argv[]) 
{
}

first arg or argv[0] is the COMMAND


***********************FILE I/0***********************************

ifstream ifile; //create object instance to bring in stuff from files
	
ifile.open(filename); //open file stream
ifile.close(filename); //close filestream

ifile >> numbers[i] >> items[i]; //cin file contents into the arrays variables. 


while (!(ifile.fail())) //use if u dont know how much is in file as u put into array
{
	ifile >> numbers[i] >> items[i];
}


//.fail stuff
 ifstream ifile; 

  ifile.open(argv[1]);

  if (ifile.fail()) // to check if u can open file
  {
  	cout << "Unable to open file" << endl;
  	return 1;
  }

  int numWords;
  ifile >> numWords; 

  if (ifile.fail()) //to check if integer
  {
  	cout << "Failed to read an integer!" << endl;
  	return 1;
  }

//ofstream stuff

ofstream ofile; 

ofile.open(new file filename); //puts stuff in a new file that u make 
ofile << "dicks" << endl;

ofile.close(new file filename);

***********************Dyanmic memory***************************

//jagged array
 char** wordBank = new char* [numWords]; //dynamically allocate right amount of memory for num of words

  char buffer[41]; //buffer used for cpy and find length of word

  for (int i = 0; i < numWords; i++)
  {
  	ifile >> buffer; //bring in line of text
  	int len = strlen(buffer); //find length of word
  	char* temp = new char[len+1]; //temp makes a specified amount of incdices for word ur abt to copy
  	strcpy(temp, buffer); //copy word into the space u made
  	wordBank[i] = temp; //store address to array u made
   }

 // Pick a random word from the wordBank
  int target = rand() % numWords;
  int targetLen = strlen(wordBank[target]);


  // Make a dynamically-allocated copy of the word and scramble it
  char* word = new char[targetLen+1];
  strcpy(word, wordBank[target]);
  permute(word, targetLen);


show how to delete dynamically allocated memory

