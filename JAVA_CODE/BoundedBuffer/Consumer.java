/*
* This is the Consumer class. It has a constructor for shared buffer.
* This class continually takes from the buffer untill a isTerminate
* message is read in which it exits.
*
* @author  Dustin Follett
* @since   11-30-19
*/

public class Consumer extends Thread{

  public BoundedBuffer buffer;
  public Message message;

  Consumer(BoundedBuffer buffer){
    this.buffer = buffer;
  }

  public void run(){
    try{

      while(true){

          Message message = buffer.take();
          BufferTest.itemCount--;

          System.out.println("Consumer "+currentThread().getName() + ": Reads something from buffer: "+ message.toString());
          System.out.println();

          int sleep = ((int) (Math.random()*((10500-5500)+1))+5500);
          System.out.println("Consumer "+currentThread().getName()+" will sleep for : "+sleep+" milliseconds.");
          Thread.sleep(sleep);

          if(message.toString().equals("")){
            System.out.println("Consumer "+currentThread().getName() +": got the terminate message... Thread Now Exiting");
            BufferTest.termCount++;
            System.out.println("Producer: Consumer "+currentThread().getName() +": Has Exited");
            return;
          }
      }
    }
    catch(Exception e){
    }
  }
}
