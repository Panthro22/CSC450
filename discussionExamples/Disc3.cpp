// Display vulerablites of string formatting
// Injection attack
// Unvalidated User input
// Buffer Overflow
// Then show a properly secured version of the code
// ---------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

int main()
{
  // example of injeciton attack and unvalidated user input
  // user input to cause injection attack to output some memory addresses

  char name[50];
  printf("Enter your name: ");
  gets(name);
  printf(name);
  printf("\n");

  // example of buffer overflow
  // user input to cause buffer overflow to output some memory addresses
  char buffer[3];
  cout << "Enter a string: " << endl;
  cin >> buffer;
  cout << "You entered: " << buffer << endl;
  // large input can cuase other memory to be overwritten and still display the correct output
}