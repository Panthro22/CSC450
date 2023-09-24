#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool isSafeInput(const string &input)
{
  // Regular expression to check for safe input (letters, numbers, and spaces)
  regex pattern("^[A-Za-z0-9 ]+$");
  return regex_match(input, pattern);
}

int main()
{
  for (int i = 0; i < 3; i++)
  {
    // Print the iteration number to show the user which iteration they are on
    cout << "Iteration " << i + 1 << endl;

    // Prompt the user to enter the first string
    cout << "Enter the first string (up to 255 characters): ";
    string firstString;
    getline(cin, firstString);

    // Validate the first input
    while (!isSafeInput(firstString) || firstString.length() > 255)
    {
      !isSafeInput(firstString) ? cout << "Invalid input. Please enter only alphanumeric characters (up to 255 characters):" << endl : cout << "Invalid input. Please enter only alphanumeric characters (up to 255 characters):" << endl;
      cout << "Enter the first string: "; // Reprompt for input
      getline(cin, firstString);
    }

    // Prompt the user to enter the second string
    cout << "Enter the second string (up to 255 characters): ";
    string secondString;
    getline(cin, secondString);

    // Validate the second input
    while (!isSafeInput(secondString) || secondString.length() > 255)
    {
      !isSafeInput(secondString) ? cout << "Invalid input. Please enter only alphanumeric characters up to 255 characters: " << endl : cout << "Invalid input. Please enter only alphanumeric characters up to 255 characters: " << endl;
      cout << "Enter the second string: "; // Reprompt for input
      getline(cin, secondString);
    }

    // Concatenate the two strings
    string concatenatedString = firstString + secondString;

    // Print the concatenated string
    cout << "Final String: " << concatenatedString << endl;
  }

  return 0;
}
