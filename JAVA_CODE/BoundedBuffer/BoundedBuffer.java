/*
* This is the BoundedBuffer class. It has a constructor to reference size.
* Handles the access of critical section. Bassically what is found on javas
* API for concurrentlocks.
*
* @author  Dustin Follett
* @since   11-30-19
*/

import java.util.concurrent.locks.*;

class BoundedBuffer {
  final Lock lock = new ReentrantLock();
  final Condition notFull  = lock.newCondition();
  final Condition notEmpty = lock.newCondition();
  final Message[] items = new Message[BufferTest.size];

  public int putptr, takeptr, count, size;

  BoundedBuffer(int size){
    this.size = size;
  }

  public void put(Message x) throws InterruptedException {
    lock.lock();
    try {
      if(size == BufferTest.itemCount){
        System.out.println("Producer waiting cause Buffer is full...");
      }
      while (size == count)
        notFull.await();
      items[putptr] = x;
      if (++putptr == items.length)
        putptr = 0;
      ++count;
      notEmpty.signal();
    } finally {
      lock.unlock();
    }
  }

  public Message take() throws InterruptedException {
    lock.lock();
    try {
      if(count == 0){
        System.out.println("Consumer "+Thread.currentThread().getName() +" waiting cause Buffer is empty...");
      }
      while (count==0)
        notEmpty.await();
      Message x = items[takeptr];
      if (++takeptr == items.length)
        takeptr = 0;
      --count;
      notFull.signal();
      return x;
    } finally {
      lock.unlock();
    }
  }
}
