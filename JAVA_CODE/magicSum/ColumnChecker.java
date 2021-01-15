/*
* This is the ColumnChecker class that checks each col and inputs its
* awnsers into the awnser array.
*
* @author  Dustin Follett
* @since   11-19-19
*/

public class ColumnChecker extends Thread{
    //instance variables
    public int[][] mArray;
    public int colNum;
    public int[] awns;

    //constructor for colChecker
    public ColumnChecker (int[][] mArray,int colNum,int[] awns){
      this.mArray = mArray;
      this.colNum = colNum;
      this.awns = awns;
    }

    //run function that is called when thread is created.
    public void run(){
      System.out.println("Thread col checker "+colNum+" is taking a nap! zzz...");
      //sleeps for random value
      try{
        int sleep = ((int) (Math.random()*5000));
        Thread.sleep(sleep);
      }
      catch (Exception e){
        System.out.println(e);
      }

      int sum = 0;
      System.out.println("Thread col checker "+colNum+" snorts and wakes up!");
      //sums its respective column in the shared array
      for(int j = 0; j <= MagicSum.size-1; j++){
        sum = sum + mArray[j][colNum-1];
      }
      System.out.println();
      System.out.println("Thread col checker "+colNum+": sum is "+sum);
      System.out.println();

      //stores sum in awnser array in the n->n+n range of indexes in the array
      awns[colNum-1+MagicSum.size] = sum;

      //marks the end of col threads
      if(colNum==MagicSum.size){
        MagicSum.colFinished=true;
      }
    }
  }
