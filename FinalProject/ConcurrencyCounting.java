package CSC450JavaPrograms;

public class ConcurrencyCounting {

  private static final int MAX_COUNT = 20;
  private static int counter = 0;

  public static void main(String[] args) {
    // thread1 and thread2 are accessing the same variable counter
    // using the synchronized methods
    Thread thread1 = new Thread(() -> incrementCounter());
    Thread thread2 = new Thread(() -> decrementCounter());

    thread1.start();
    thread2.start();

    try {
      thread1.join();
      thread2.join();
    } catch (InterruptedException e) {
      Thread.currentThread().interrupt();
    }
  }

  // synchronized methods to increment and decrement the counter
  // keyword synchronized is used to lock the object
  // so that only one thread can access the object at a time
  // to change the value of the counter
  public static synchronized void incrementCounter() {
    System.out.println(
      "Thread 1: " +
      Thread.currentThread().getId() +
      " is running inside incrementCounter()"
    );
    System.out.println("Thread 1: Counter = " + counter);
    // Count up to MAX_COUNT
    while (counter < MAX_COUNT) {
      counter++;
      System.out.println("Thread 1: Counting up - " + counter);
      try {
        Thread.sleep(100); // Slow down the thread so that the output is seeable
      } catch (InterruptedException e) {
        Thread.currentThread().interrupt();
      }
    }
  }

  public static synchronized void decrementCounter() {
    System.out.println(
      "Thread 2: " +
      Thread.currentThread().getId() +
      " is running inside decrementCounter()"
    );
    System.out.println("Thread 2: Counter = " + counter);
    while (counter > 0) { // Check the counter value and decrement it as needed
      counter--;
      System.out.println("Thread 2: Counting down - " + counter);
      try {
        Thread.sleep(100); // Slow down the thread so that the output is seeable
      } catch (InterruptedException e) {
        Thread.currentThread().interrupt();
      }
    }
  }
}
