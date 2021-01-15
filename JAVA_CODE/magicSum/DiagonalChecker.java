/*
* This is the DiagonalChecker class that checks the two Diagonals
* and inputs those sums into the awnser array.
*
* @author  Dustin Follett
* @since   11-19-19
*/

public class DiagonalChecker extends Thread{
    //instance variables
    public int[][] mArray;
    public int diagNum;
    public int[] awns;

    //constructor
    public DiagonalChecker (int[][] mArray,int diagNum,int[] awns){
      this.mArray = mArray;
      this.diagNum = diagNum;
      this.awns = awns;
    }

    //function called when diagonal thread created.
    public void run(){
      System.out.println("Thread diagonal checker "+diagNum+" is taking a nap! zzz...");
      //sleeps for random time under 5 seconds.
      try{
        int sleep = ((int) (Math.random()*5000));
        Thread.sleep(sleep);
      }

      catch (Exception e){
        System.out.println(e);
      }

      //there is only ever 2 diagonals.
      int sum1 = 0;
      int sum2 = 0;
      System.out.println("Thread diagonal checker "+diagNum+" snorts and wakes up!");
      for(int i = 0; i <= MagicSum.size-1; i++){
        for(int j = 0; j <= MagicSum.size-1; j++){
          //summing left to right diagonal
          if (i==j)
            sum1 = sum1 + mArray[i][j];
          //summing right to left diagonal
          if ((i+j)==(MagicSum.size-1))
            sum2 = sum2 + mArray[i][j];
        }
      }
      //stores diagonals in the last two indexes of awnser array
      //if diagonal is left to right
      if(this.diagNum==1){
        System.out.println();
        System.out.println("Thread diagonal checker "+diagNum+": sum is "+sum1);
        System.out.println();
        awns[diagNum-1+MagicSum.size*2] = sum1;
      }
      //if diagonal is right to left
      if(diagNum==2){
        System.out.println();
        System.out.println("Thread diagonal checker "+diagNum+": sum is "+sum2);
        System.out.println();
        awns[diagNum-1+MagicSum.size*2] = sum2;
      }

      //diagonals are completed
      if(diagNum == 2){
        MagicSum.diagFinished=true;
      }

    }
  }
