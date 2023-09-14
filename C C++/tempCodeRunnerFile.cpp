#include <iostream>
#include <cfloat>
#include <climits>

int main()
{
  // Default Values
  int cplusplusInt;
  bool cplusplusBool;
  double cplusplusDouble;

  std::cout << "C++ Default Values:" << std::endl;
  std::cout << "Uninitialized int: " << cplusplusInt << std::endl;       // May contain garbage value
  std::cout << "Uninitialized bool: " << cplusplusBool << std::endl;     // May contain garbage value
  std::cout << "Uninitialized double: " << cplusplusDouble << std::endl; // May contain garbage value
  return 0;
}