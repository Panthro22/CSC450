#include <iostream>

using namespace std;

// function to change odd elements to 0 with only the pointer passed in
void NoMoreOdds(int *ptr, int size)
{
  // for loop using pointer arithmetic to access the elements of arr
  // while changing odd elements to 0 inside of the function NoMoreOdds
  for (int i = 0; i < size; i++)
  {
    if (*(ptr + i) % 2 != 0)
    {
      *(ptr + i) = 0;
    }
  }
}

int main()
{
  // showing the use of pointers with arrays and how to access the elements
  int arr[5] = {41, 32, 45, 25, 15};
  int *ptr = arr; // ptr points to the first element of arr
  // print out of the values of arr using the pointer.
  for (int i = 0; i < 5; i++)
  {
    cout << *(ptr + i) << endl;
  }
  // Calculate the size of the array
  int size = sizeof(arr) / sizeof(arr[0]);
  // sizeof(arr) returns the size of the array in bytes
  // sizeof(arr[0]) returns the size of the first element of the array in bytes
  // dividing the size of the array in bytes by the size of the first element of the array in bytes

  // for loop using pointer arithmetic to access the elements of arr
  // while changing odd elements to 0 inside of the function NoMoreOdds
  // we are passing the memory address of the first element of arr to the function via the pointer
  NoMoreOdds(ptr, size);
  cout << "Orignal Completed " << endl;
  cout << endl;
  cout << "After NoMoreOdds function call" << endl;
  // print out of the values of arr using the pointer after the function call.
  for (int i = 0; i < 5; i++)
  {
    cout << *(ptr + i) << endl;
  }

  int arr2[5] = {41, 32, 45, 25, 15};
  ptr = arr2; // ptr points to the first element of arr

  // Accessing elements using the pointer
  int firstElement = *ptr;        // equals 41
  int secondElement = *(ptr + 1); // equals 32

  int variableName = 42;
  ptr = &variableName; // ptr now holds the memory address of variableName because of & infront.

  int y = *ptr; // y now contains the value 42 (value pointed to by ptr)

#define MAX 3 // MAX is a constant that is defined to be 3 or can be done with #define MAX 3

  int variable[MAX] = {10, 100, 200}; // This is an array of integers

  for (int index = 0; index < MAX; index++)
  {
    *variable = index; // This is correct. You can assign a value to a pointer. This is the same as variable[index] = index;
    ptr++;             // This is correct. You can increment a pointer
    variable++;        // This is incorrect. You cannot increment a variable array as a pointer because it is a constant.
  }

  return 0;

  // int *dynamicArr = new int[10]; // Dynamically allocate a pointer to an array of 10 integers on the heap
}