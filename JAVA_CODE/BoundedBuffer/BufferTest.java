/*
* This is the BufferTest class. It uses arguments to set up the
* size of the buffer and number of consumers.
* There are four classes one for rows, one for BufferTest / Producer,
* one for the BoundedBuffer, one for Consumers, and one for Message.
* This class sets up a producer that handles all Consumers. it also
* contains the implementation of producer.
*
* @author  Dustin Follett
* @since   11-30-19
*/

import java.io.*;
import java.util.*;
import java.lang.*;


public class BufferTest extends Thread{
  public static int size,numConsumers,termCount,itemCount;
  public static BoundedBuffer buffer;

  public static void main(String[] args){
    try{
      //sets size of buffer and amt of consumers
      BufferTest.size = Integer.parseInt(args[0]);
      BufferTest.numConsumers = Integer.parseInt(args[1]);
    }
    catch(Exception e){
      System.out.println("Please enter two args: 1 for size of bounded buffers, and 2 how many consumers.");
      System.exit(0);
    }

    //new bounded buffer
    BoundedBuffer buffer = new BoundedBuffer(BufferTest.size);

    System.out.println("hello from BufferTest:main()");

    //new producer
    BufferTest producer = new BufferTest(buffer);
    producer.setName("Producer");
    producer.start();

    //wait for producer to finish
    try {
      producer.join();
    }
    catch (InterruptedException e) {
      e.printStackTrace();
    }

    System.out.println();
    System.out.println("Thanks for Buffering!");
    System.exit(0);
  }

  //aka producer
  public BufferTest(BoundedBuffer buffer){
    this.buffer = buffer;
  }

    public void run(){
      Consumer[] consumers = new Consumer[BufferTest.size];

      //start consumer threads
      for(int i = 1; i<BufferTest.numConsumers+1; i++){
        consumers[i] = new Consumer(buffer);
        consumers[i].setName(String.valueOf(i));
        consumers[i].start();
      }
      //get input while consumers still running
      while(BufferTest.termCount<=BufferTest.numConsumers+1){
        try{
            System.out.print(Thread.currentThread().getName() +" : Input Message: ");
            Message message = new Message(System.console().readLine());

            //puts what got in buffer
            BufferTest.buffer.put(message);
            BufferTest.itemCount++;

            System.out.println("inputting this: "+message.toString());

            if(message.isTerminate(message)){
              //keeps track of closed consumers
              BufferTest.termCount++;
            }
        }
      catch(Exception e){}
    }

    //waits for all consumers to finish
    for(int i=1;i<=BufferTest.numConsumers+1;i++){
      try {
        consumers[i].join();
      }
      catch (Exception e) {
      }
    }
  }
}
