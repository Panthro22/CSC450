package CSC450JavaPrograms;

public class ConcurrencyCountingNonStatic {

  private final int MAX_COUNT = 20;
  private int counter = 0;

  public static void main(String[] args) {
    ConcurrencyCountingNonStatic concurrencyCountingNonStatic = new ConcurrencyCountingNonStatic();
    // thread1 and thread2 are accessing the same variable counter
    // using the locking the variable counter
    Thread thread1 = new Thread(() ->
      concurrencyCountingNonStatic.incrementCounter()
    );
    Thread thread2 = new Thread(() ->
      concurrencyCountingNonStatic.decrementCounter()
    );

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
  public void incrementCounter() {
    System.out.println(
      "Thread 1: " +
      Thread.currentThread().getId() +
      " is running inside incrementCounter()"
    );
    synchronized (this) {
      // lock the varible counter from being accessed by other threads
      // Count up to MAX_COUNT
      while (counter < MAX_COUNT) {
        // lock the varible counter

        counter++;
        System.out.println("Thread 1: Counting up - " + counter);
        try {
          Thread.sleep(100); // Slow down the thread so that the output is seeable
        } catch (InterruptedException e) {
          Thread.currentThread().interrupt();
        }
      }
    }
  }

  public void decrementCounter() {
    System.out.println(
      "Thread 2: " +
      Thread.currentThread().getId() +
      " is running inside decrementCounter()"
    );
    synchronized (this) {
      // lock the varible counter from being accessed by other threads
      while (counter > 0) { // Check the counter value and decrement it as needed
        // lock the varible counter
        synchronized (this) {
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
  }
}
