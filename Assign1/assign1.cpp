/**
 *
 * CSCI 241 Assignment 1
 *
 * Author:  Cortland Ervins
 * z-ID:    Z1813736
 * Date:    2/9/19
 *
 * This program tests functions for manipulating C strings.
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include <stdio.h>

using std::cin;
using std::cout;
using std::endl;



// Add your function prototypes here

char* copy(char* destination, const char* source, size_t num) ;

char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num);

char* caseChangeCopy(char* destination, const char* source, size_t num) ;

char* reverseCopy(char* destination, const char* source, size_t num);

void read(char* destination, int num);

int main()
   {
   const int WORDSIZE = 15;
   char words[][WORDSIZE] = {"sprightful", "reason to row", "New York", "Bolton", "Frida", ""};
   char word[WORDSIZE];

   // Test the copy function
   cout << "Copy \"sprightful\", should see \"sprightful\".\n";
   copy(word, words[0], sizeof(word) - 1);
  cout << word << endl << endl;

   // Test the limit on the copy function
   cout << "Copy \"Supercalifragilisticexpialidocious\", should see \"Super\".\n";
   copy(word, "Supercalifragilisticexpialidocious", 5);
   cout << word << endl << endl;

   // Test the replaceCopy function
   cout << "Replace 'r' in \"reason to row\" with 's', should see \"season to sow\".\n";
   replaceCopy(word, words[1], 'r', 's', sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the replaceCopy function
   cout << "Replace 's' in \"Supercalifragilistic\" with 'd', should see \"duper\".\n";
   replaceCopy(word, "Supercalifragilistic", 'S', 'd', 5);
   cout << word << endl << endl;

   // Test the caseChangeCopy function
   cout << "Case change \"New York\", should see \"nEW yORK\".\n";
   caseChangeCopy(word, words[2], sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the caseChangeCopy function
   cout << "Case change \"Supercalifragilistic\", should see \"sUPER\".\n";
   caseChangeCopy(word, "Supercalifragilistic", 5);
   cout << word << endl << endl;

   // Test the reverseCopy function
   cout << "Reverse \"Bolton\", should see \"notloB\"\n";
   reverseCopy(word, words[3], sizeof(word) - 1);;
   cout << word << endl << endl;

   // Test the limit on the reverseCopy function
   cout << "Reverse \"cytogeneticists\", should see \"tsicitenegotyc\"\n";
   reverseCopy(word, "cytogeneticists", sizeof(word) - 1);;
   cout << word << endl << endl;

   cout << "Reverse \"Frida\", change case, and replace 'D' with 'Z', should see \"AZIRf\".\n";
   replaceCopy(caseChangeCopy(reverseCopy(word, words[4], sizeof(word) - 1), word, sizeof(word) - 1), word, 'D', 'Z', sizeof(word) - 1);
   cout << word << endl << endl;


   cout << "Enter your entire name: ";
   read(words[5], sizeof(words[5]));
   cout << words[5] << endl << endl;

   cout << "Reverse your name and change case.\n";
  cout << caseChangeCopy(reverseCopy(word, words[5], sizeof(word) - 1), word, sizeof(word) - 1) << endl;

   return 0;
   }

// Add your function definitions here

/****************************************************************

   FUNCTION:   char* copy(char* destination, const char* source, size_t num)

   ARGUMENTS:
   char* destination: Pointer to word cstring.
   char* source: Pointer to words cstring.
   size_t num: Pointer to cstring length limit.

   RETURNS:    destination

   NOTES:      Function copies cstring from source pointer and puts it into destination pointer.
****************************************************************/


char* copy(char* destination, const char* source, size_t num)
{

int i; // Loop counter


for (i=0; i < (int)num; i++) //For loop, puts contents of source cstring into destination cstring
{

destination[i] =source[i];    // Puts contents of source cstring into destination cstring


}

destination[i] = '\0'; // Puts a null charater at the end of the cstring


return destination; // returns cstring
}

/****************************************************************

   FUNCTION:   char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num)

   ARGUMENTS:
   char* destination: Pointer to word cstring.
   char* source: Pointer to words cstring.
   char target: The letter that is being replaced.
   char replace: The letter that will replace the letter being targeted
   size_t num: Pointer to cstring length limit

   RETURNS:destination

   NOTES: Function replaces target letter after copying source cstring pointer to destination cstring pointer.
****************************************************************/


char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num)
{
int i;                       // Loop counter

for (i=0; i < (int)num; i++)  //For loop, puts contents of source cstring into destination cstring
{
	destination[i] =source[i]; // Puts contents of source cstring into destination cstring


	if(destination[i] == target) // If character in a part of the cstring is the target it gets replaced.
	{
		destination[i] = replace ; // Replaces target with different letter
	}

}

destination[i] = '\0'; // Puts a null charater at the end of the cstring


return destination; // returns cstring


}

/****************************************************************

   FUNCTION:   char* reverseCopy(char* destination, const char* source, size_t num)

   ARGUMENTS:
   char* destination: Pointer to word cstring.
   char* source: Pointer to words cstring.
   size_t num: Pointer to cstring length limit.

   RETURNS: destination

   NOTES: Copys source cstring pointer to destination cstring pointer and then reverses the cstring.
****************************************************************/

char* reverseCopy(char* destination, const char* source, size_t num)
{
	size_t length = strlen(source); //Creates unsigned int that is the length of the source cstring

	int limit; // Int that will be used to limit how long cstring can be

		if (length < num) // If string length is  smaller than num, limit is  length - 1
		{

	limit = length -1;
        }

	else //If  string lenth is larger than num, limit is num -1
	 limit = num -1;


	int i; // Loop counter

  	for (i=0; i < (int)num; i++) //For loop, puts contents of source cstring into destination cstring
{
		destination[i] =source[i];  // Puts contents of source cstring into destination cstring

	if (destination[num] == source[num]) //Checks if the cstring limit has been reached
	{
   destination[num] = '\0'; // Puts in null character at the end of sctring
	}


}

   for (i =0; limit >= 0; i++, limit--) // For loop that inserts the source string in to the destination string in reverse order.

{
	destination[limit] = source[i];

}
 destination[i] = '\0' ; // Puts null character at the end of cstring

 return destination; // returns cstring
}


/****************************************************************

   FUNCTION: char* caseChangeCopy(char* destination, const char* source, size_t num)

   ARGUMENTS:
   char* destination: Pointer to word cstring.
   char* source: Pointer to words cstring.
   size_t num: Pointer to cstring length limit.


   RETURNS: destination

   NOTES:  Copys source cstring pointer to destination cstring pointer, then reverses the case of each letter.
****************************************************************/


char* caseChangeCopy(char* destination, const char* source, size_t num)
{

int i; // Loop counter


for (i=0; i < int(num); i++) //For loop, puts contents of source cstring into destination cstring
{
	destination[i] =source[i]; // Puts contents of source cstring into destination cstring



	if (islower(destination[i]) ) // Checks if letter in destination pointer cstring is lowercase
	{
		destination[i] =	toupper(destination[i]); //Changes lowercase letter to uppercase
	}
	else if (isupper(destination[i]) ) // Checks if letter in destination pointer cstring is uppercase
	{
		destination[i] = tolower(destination[i]); //Changes uppercase letter to lowercase
	}

}

destination[i] = '\0'; // Puts null character at the end of cstring

 return destination; //Returns destination

}

/****************************************************************

   FUNCTION:   void read(char* destination, int num)

   ARGUMENTS:
   char* destination: Pointer to word cstring.
   int num: pointer to num

   RETURNS:  User input

   NOTES:  User inputs their name
****************************************************************/

void read(char* destination, int num)
{

	std::cin.getline(destination,num); // User inputs their name

}

