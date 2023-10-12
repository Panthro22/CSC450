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
  // example of injeciton attack
  // user input to cause injection attack to display address of name: name
  try
  {
    char name[50];
    printf("Enter your name: ");
    gets(name);
    printf("Hello, %s!\n", name);
  }
  catch (const std::exception &ex)
  {
    cerr << "Injection attack: " << ex.what() << endl;
  }
  catch (...)
  {
    cerr << "Injection attack: Undefined behavior" << endl;
  }

  // example of unvalidated user input
  try
  {
    int age;
    cout << "Enter your age: ";
    cin >> age;
    cout << "You are " << age << " years old" << endl;
  }
  catch (...)
  {
    cout << "Unvalidated user input" << endl;
  }

  // example of buffer overflow
  try
  {
    char buffer[3];
    cout << "Enter a string: " << endl;
    cin >> buffer;
    cout << "You entered: " << buffer << endl;
    if (buffer[3] != '\0')
    {
      throw "Buffer overflow";
    }
  }
  catch (...)
  {
    cout << "Buffer overflow" << endl;
  }

  return 0;
}