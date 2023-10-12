#include <iostream>
#include <fstream>
#include <string>
#include <limits> // For numeric_limits
#include <regex>

using namespace std;

// Function to append user input to the specified file
void appendToFile(const string &filename, const string &data)
{
  ofstream outFile(filename, ios::app); // Open the file in append mode
  if (outFile.is_open())
  {
    outFile << data << endl; // Append the data to the file
    outFile.close();         // Close the file
    cout << "Data appended to " << filename << " successfully." << endl;
  }
  else
  {
    cerr << "Unable to open file: " << filename << endl;
  }
}

// Function to reverse a string
string reverseString(const string &str)
{
  string reversedStr = str; // Copy the string
  int start = 0;
  int end = str.length() - 1;

  while (start < end)
  {
    swap(reversedStr[start], reversedStr[end]); // Swap the characters
    start++;                                    // Increment start
    end--;                                      // Decrement end
  }

  return reversedStr; // Return the reversed string
}

// Function to validate user input against a regex pattern
bool validateInput(const string &input)
{
  // Define a regex pattern that allows letters, digits, '.', ',', '!', and '?'
  regex pattern("^[A-Za-z0-9.,?! ]*$");

  return regex_match(input, pattern);
}

int main()
{
  string userInput;
  ifstream inFile; // Declare inFile here

  while (true)
  {
    // Get user input
    cout << "Enter text to append to CSC450_CT5_mod5.txt (or type 'quit' to exit): ";
    getline(cin, userInput);

    // Check if the user wants to exit
    if (userInput == "quit")
    {
      break; // Exit the loop
    }

    // Validate user input
    if (!validateInput(userInput))
    {
      cerr << "Invalid input. Please provide text with only letters, digits, '.', ',', and '?'." << endl;
      continue; // Skip this iteration and prompt for input again
    }

    // Append user input to the file
    appendToFile("CSC450_CT5_mod5.txt", userInput);
  }

  // Open the input file for reading
  inFile.open("CSC450_CT5_mod5.txt");
  if (!inFile.is_open())
  {
    cerr << "Unable to open CSC450_CT5_mod5.txt for reading." << endl;
    return 1;
  }

  // Read the contents of the input file
  string fileContent((istreambuf_iterator<char>(inFile)), (istreambuf_iterator<char>())); // Read the entire file
  inFile.close();                                                                         // Close the file

  // Reverse the content
  string reversedContent = reverseString(fileContent); // Reverse the content

  // Write the reversed content to CSC450-mod5-reverse.txt
  ofstream outFile("CSC450-mod5-reverse.txt"); // Open the file for writing
  if (outFile.is_open())                       // Check if the file is open
  {
    outFile << reversedContent; // Write the reversed content to the file
    outFile.close();
    cout << "Reversed content saved to CSC450-mod5-reverse.txt." << endl;
  }
  else
  {
    cerr << "Unable to open CSC450-mod5-reverse.txt for writing." << endl;
    return 1;
  }

  return 0;
}
