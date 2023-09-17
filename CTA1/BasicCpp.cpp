#include <iostream>
#include <string>

// isInteger checks if a string is an integer
bool isInteger(const std::string &str)
{
  for (char c : str) // for loop goes through each character in the string
  {
    if (!std::isdigit(c)) // if the character is not a digit
    {
      return false;
    }
  }
  return true; // if all characters are digits
}

int main()
{
  // Declare variables to store person's information
  std::string firstName, lastName, streetAddress, city, zipCode;

  // Prompt the user to enter information
  std::cout << "Enter First Name: ";
  std::cin >> firstName;

  std::cout << "Enter Last Name: ";
  std::cin >> lastName;

  std::cin.ignore(); // Clear the newline character from the buffer

  std::cout << "Enter Street Address: ";
  std::getline(std::cin, streetAddress);

  std::cout << "Enter City: ";
  std::getline(std::cin, city);

  bool validZip = false;
  while (!validZip)
  {
    std::cout << "Enter Zip Code (5 digits): ";
    std::cin >> zipCode;

    if (zipCode.length() == 5 && isInteger(zipCode))
    {
      validZip = true;
    }
    else
    {
      std::cout << "Invalid ZIP code. Please enter 5 digits." << std::endl;
    }
  }

  // Print the person's information
  std::cout << "\nFictional Person Information:\n";
  std::cout << "First Name: " << firstName << std::endl;
  std::cout << "Last Name: " << lastName << std::endl;
  std::cout << "Street Address: " << streetAddress << std::endl;
  std::cout << "City: " << city << std::endl;
  std::cout << "Zip Code: " << zipCode << std::endl;

  return 0;
}
