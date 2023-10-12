#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// mutex for critical section such as shared data. This mutex will be used to protect sharedValue
mutex mtx;
void safe_increment(int &value) // pass by reference
{
  lock_guard<mutex> lock(mtx); // lock_guard will unlock mutex when it goes out of scope.
  ++value;                     // increment value
  cout << "Shared value after modified inside safe_increment: " << value << endl;
  cout << "Thread ID: " << this_thread::get_id() << endl;
}

// Function for both threads to increment the shared resource without locking
void race_increment(int &value)
{
  for (int i = 0; i < 1000000; ++i)
  {
    ++value; // Increment sharedValue without synchronization
  }
}

int main()
{
  int sharedValue = 0;
  // ref is used to pass by reference to thread, otherwise it will pass by value
  thread t1(safe_increment, ref(sharedValue));
  // t1 thread id
  cout << "T1 Thread ID: " << t1.get_id() << endl;
  thread t2(safe_increment, ref(sharedValue));
  // t2 thread id
  cout << "T2 Thread ID: " << t2.get_id() << endl;
  cout << "Shared value before T1 join: " << sharedValue << endl;
  t1.join(); // wait for t1 to finish and release the thread resource
  cout << "Shared value after T1 join: " << sharedValue << endl;
  t2.join(); // wait for t2 to join main thread
  cout << "Shared value after T2 join: " << sharedValue << endl;
  cout << "Let the race begin!" << endl;
  sharedValue = 0;                             // reset sharedValue for race
  thread t3(race_increment, ref(sharedValue)); // create thread t3
  thread t4(race_increment, ref(sharedValue)); // create thread t4
  t3.join();
  cout << "Shared value race after T3 join: " << sharedValue << endl;
  t4.join();
  cout << "Shared value race after T4 join: " << sharedValue << endl;
  return 0;
}
