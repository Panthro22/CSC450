#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx; // Define a mutex to protect the counter
int counter = 0;
const int MAX_COUNT = 20; // Define the maximum count value

void CountUp()
{
  lock_guard<mutex> lock(mtx);
  cout << "Thread 1: Count is " << counter << endl;
  for (int increment = 1; increment <= MAX_COUNT; ++increment) // Count up to the maximum count
  {
    this_thread::sleep_for(chrono::milliseconds(100));
    if (counter < MAX_COUNT) // Check if the counter is within bounds
    {
      counter++;
      cout << "Thread 1: Counting up - " << counter << endl;
    }
    else
    {
      cout << "Thread 1: Reached the maximum count of " << MAX_COUNT << endl;
      break; // Exit the loop when the maximum count is reached
    }
  }
}

void CountDown()
{
  int troubleTracker = 0;
  while (counter != MAX_COUNT) // Check if the other thread has finished counting up to the maximum count
  {
    troubleTracker++;
    this_thread::sleep_for(chrono::milliseconds(500));
    if (troubleTracker > 11) // Push message to the console if the other thread is taking too long
    {
      cout << "Thread 2: Trouble! Counter is " << counter << endl;
      cout << "Thread 1: Has not finished counting up yet to " << MAX_COUNT << "!" << endl;
      break;
    } // this does not stop or prevent deadlock
  }
  lock_guard<mutex> lock(mtx);
  cout << "Thread 2: Count is " << counter << endl;
  while (true) // Count down to the minimum count
  {
    this_thread::sleep_for(chrono::milliseconds(100));
    if (counter >= 1) // Check if the counter is within bounds
    {
      counter--;
      cout << "Thread 2: Counting down - " << counter << endl;
    }
    if (counter == 0) // Exit the loop when the minimum count is reached
    {
      cout << "Thread 2: Reached the minimum count of 0" << endl;
      break;
    }
  }
}

int main()
{
  thread thread1(CountUp);
  thread thread2(CountDown);

  // Wait for the threads to finish
  thread1.join();
  thread2.join();

  return 0;
}
