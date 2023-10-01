#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int acceptableInteger()
{
  char userInput;
  string numString;
  int finalInput;
  while (true) // Loop through until the user enters an all integers for input
               // then store the integer value in finalInput
  {
    cin >> userInput;       // Get the user input
    if (isdigit(userInput)) // Check if the user input is a digit
    {
      numString += userInput; // If it is a digit, add it to the string
    }
    else // If the user input is not a digit or a newline, inform the user
    {
      cout << "Invalid input. Please enter an integer value." << endl;
      cout << "Integer: ";
      numString = "";          // Clear the string
      cin.clear();             // Clear the input stream
      cin.ignore(10000, '\n'); // Ignore the next 10000 characters or until a newline
    }
    // check if there is newline character in the input stream
    if (cin.peek() == '\n')
    {
      break; // Exit the loop if the next character is a newline
    }
  }

  finalInput = stoi(numString); // Convert the numString to an integer, Storing the integer values in finalInput. stoi() is a function that converts a string to an integer
  return finalInput;            // Return the integer value
}

int main()
{
  // Declare three integer variables
  int one, two, three;

  // Inform the user to enter three integer values
  cout << "Enter three integer values:" << endl;
  cout << "Integer one: ";
  one = acceptableInteger(); // Call the function to get an integer value
  cout << "Integer two: ";
  two = acceptableInteger();
  cout << "Integer three: ";
  three = acceptableInteger();

  // Create integer pointers and allocate memory using new
  // Pointers have a new address in memory
  int *ptrOne = new int;
  int *ptrTwo = new int;
  int *ptrThree = new int;

  // Assign values to the dynamically allocated memory
  *ptrOne = one;
  *ptrTwo = two;
  *ptrThree = three;

  // Display the contents of variables
  cout << "Contents of variables:" << endl;
  cout << "Integer one: " << one << endl;
  cout << "Integer two: " << two << endl;
  cout << "Integer three: " << three << endl;
  // Display variable addresses
  cout << "Addresses of variables:" << endl;
  cout << "Integer one: " << &one << endl;
  cout << "Integer two: " << &two << endl;
  cout << "Integer three: " << &three << endl;

  // Display the contents of pointers
  cout << "Contents of pointers:" << endl;
  cout << "ptrOne: " << *ptrOne << endl;
  cout << "ptrTwo: " << *ptrTwo << endl;
  cout << "ptrThree: " << *ptrThree << endl;
  // Display pointer addresses
  cout << "Addresses of pointers:" << endl;
  cout << "ptrOne: " << ptrOne << endl;
  cout << "ptrTwo: " << ptrTwo << endl;
  cout << "ptrThree: " << ptrThree << endl;

  // Deallocate the dynamically allocated memory using delete
  delete ptrOne;
  delete ptrTwo;
  delete ptrThree;

  return 0;
}