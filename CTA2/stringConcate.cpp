#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool isSafeInput(const string &input)
{
  // Regular expression to check for safe input to eliminate special characters
  regex pattern("^[A-Za-z0-9 ]+$");
  return regex_match(input, pattern);
}
string getValidInput()
{
  string userInput;

  while (true)
  {
    getline(cin, userInput);

    // Validate the input
    if (userInput.length() > 255)
    {
      cout << "Invalid amount of Characters. Please enter up to 255 characters." << endl;
      cout << "Enter the string: "; // Reprompt for input
    }
    else if (!isSafeInput(userInput))
    {
      cout << "Invalid Characters. Please enter only alphanumeric characters." << endl;
      cout << "Enter the string: "; // Reprompt for input
    }
    else
    {
      break; // Input is valid, exit the loop Since loop is infinitely true, we need to break out of it
    }
  }
  return userInput;
}
int main()
{
  for (int i = 0; i < 3; i++)
  {
    // Print the iteration number to show the user which iteration they are on
    cout << "Iteration " << i + 1 << endl;

    // Prompt the user to enter the first string
    cout << "Enter the first string up to 255 characters: ";
    string firstString = getValidInput();

    // Prompt the user to enter the second string
    cout << "Enter the second string up to 255 characters: ";
    string secondString = getValidInput();

    // Concatenate the two strings
    string concatenatedString = firstString + secondString;

    // Print the concatenated string
    cout << "Final String: " << concatenatedString << endl;
  }

  return 0; // End of main needed for C++ programs to compile successfully otherwise you get a linker error
}
