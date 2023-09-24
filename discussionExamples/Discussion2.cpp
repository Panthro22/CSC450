#include <iostream>
#include <cstring>
#include <string>
#include <stdexcept>
#include <sqlite3.h>

using namespace std;

int main()
{
  try
  {
    // Buffer Overflows
    char buffer[10];
    const char *source = "This is a long string that will cause a buffer overflow";

    // Check if the length of the source string exceeds the buffer size
    if (strlen(source) >= sizeof(buffer))
    {
      throw overflow_error("Buffer Overflow");
    }

    strncpy(buffer, source, sizeof(buffer) - 1); // Copy string with proper bounds
    buffer[sizeof(buffer) - 1] = '\0';           // Ensure null-termination
  }
  catch (const exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }
  try
  {
    cout << endl;
    // Format String Vulnerabilities
    char userInput[100];
    // Unsafe: User can provide a format string to access memory or print data
    sprintf(userInput, "%s", "User input: %s"); // Simulate user-provided format string
    printf(userInput, "Malicious Data");        // Simulate user-provided data
  }
  catch (const exception &e)
  {
    cerr << "Error: Format String Vulnerability\n";
    cerr << "Details: " << e.what() << endl;
  }
  cout << endl;
  try
  {
    // Injection Attacks
    string userInputSQL = "userInput'; DROP TABLE users --"; // Simulated SQL injection attempt

    // Use SQLite C++ library to create a database and execute the query
    sqlite3 *db;
    int rc = sqlite3_open(":memory:", &db);
    if (rc)
    {
      throw runtime_error("Cannot open database: " + string(sqlite3_errmsg(db)));
    }

    // Unsafe: User input directly used in SQL query (SQL injection)
    string query = "SELECT * FROM users WHERE username='" + userInputSQL + "'";
    rc = sqlite3_exec(db, query.c_str(), 0, 0, 0);
    if (rc != SQLITE_OK)
    {
      throw runtime_error("SQL error: " + string(sqlite3_errmsg(db)));
    }

    sqlite3_close(db);
  }
  catch (const exception &e)
  {
    cerr << "Error: Injection Attack (SQL)\n";
    cerr << "Details: " << e.what() << endl;
  }

  try
  {
    // Improper String Termination
    char unsafeBuffer[105];
    strncpy(unsafeBuffer, "This is a long string", sizeof(unsafeBuffer));
  }
  catch (const exception &e)
  {
    cerr << "Error: Improper String Termination\n";
    cerr << "Details: " << e.what() << endl;
  }

  // try
  // {
  //   // Inadequate Input Validation
  //   int userInputValidation = 1; // Simulated inadequate validation
  //   // Unsafe: No validation of user input
  //   if (userInputValidation == 1)
  //   {
  //     // Perform a critical operation
  //     throw runtime_error("Invalid user input");
  //   }
  // }
  // catch (const exception &e)
  // {
  //   cerr << "Error: Inadequate Input Validation\n";
  //   cerr << "Details: " << e.what() << endl;
  // }

  return 0;

  char unsafeBuffer[100];
  strncpy(unsafeBuffer, "This is a long string", sizeof(unsafeBuffer));
  // Improper string termination is happening here becuase the string is longer than the buffer size causing
  // the string to be cut off and not properly terminated, allowing the computer to read past the end of the string
  // and potentially access memory that it should not be accessing.

  char safeBuffer[100];
  strncpy(safeBuffer, "This is a long string", sizeof(safeBuffer) - 1); // Copy with proper bounds by subtracting 1 to account for null character
  safeBuffer[sizeof(safeBuffer) - 1] = '\0';
  // Ensure null-termination by adding null character at the end of the string
}
