/*
* This is the RowChecker class that checks each row and inputs its
* awnsers into the awnser array.
*
* @author  Dustin Follett
* @since   11-19-19
*/

public class RowChecker extends Thread{
  //instance variables
  public int[][] mArray;
  public int rowNum;
  public int[] awns;

  //constructor
  public RowChecker (int[][] mArray,int rowNum,int[] awns){
    this.mArray = mArray;
    this.rowNum = rowNum;
    this.awns = awns;
  }

  //function called when thread created
  public void run(){
    System.out.println("Thread row checker "+rowNum+" is taking a nap! zzz...");
    //sleeps for random val under 5 seconds
    try{
      int sleep = ((int) (Math.random()*5000));
      Thread.sleep(sleep);
    }
    catch (Exception e){
      System.out.println(e);
    }

    int sum = 0;
    System.out.println("Thread row checker "+rowNum+" snorts and wakes up!");
    //summs the respective row
    for(int j = 0; j <= MagicSum.size-1; j++){
      sum = sum + mArray[rowNum-1][j];
    }
    System.out.println();
    System.out.println("Thread row checker "+rowNum+": sum is "+sum);
    System.out.println();

    //stores the sum in the 0->n range of the awnser array
    awns[this.rowNum-1] = sum;

    //all row threads have finished
    if(this.rowNum==MagicSum.size){
      MagicSum.rowFinished=true;
    }
  }
}
