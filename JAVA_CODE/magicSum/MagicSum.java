/*
* This is the MagicSum class. It uses a file that is
* input by commandline and is user defined. The file will contain
* a supposed magic square where each row sum col sum and diagonal
* sum equal the same number. there are three classes one for rows,
* one for columns, and one for diagonals. this main calls all nessicary
* classes and creates the threads to do the calculations on the square.
* It prints the progress and the result if its a magic square or just
* an ordinary square.
*
* @author  Dustin Follett
* @since   11-19-19
*/

import java.io.*;
import java.util.*;
import java.lang.*;

public class MagicSum extends Thread{

  public static int size;
  public static int[][] magicSquare;
  //below are variables used to see if threads are all finished.
  public static boolean rowFinished = false;
  public static boolean colFinished = false;
  public static boolean diagFinished = false;

  public static void main(String[] args){
    File file = new File(args[0]);

    //fills 2d array for reference throughout the prog.
    MagicSum.magicSquare = fillArray(file);

    //creates the array that will hold all the awnsers.
    //inatalized to 2 times ammt of rows/ cols plus the two diagonals.
    int[] awnsArr = new int[((size*2)+2)];

    //calls function that creates threads and does calculations.
    handleThreads(awnsArr);

    //print results.
    printResults(awnsArr);
  }

  public static void handleThreads(int[] awnsArr){
    System.out.println("~*~*~* MAGIC SQUARE VALIDATION PROGRAM *~*~*~");
    System.out.println();
    System.out.println("Is this a Magic Square?");
    System.out.println();
    for (int[] row : magicSquare)
      System.out.println(Arrays.toString(row));
    System.out.println();
    System.out.println("Let's find out!");
    System.out.println();

    RowChecker[] row = new RowChecker[size+1];
    ColumnChecker[] col = new ColumnChecker[size+1];
    DiagonalChecker[] diagonal = new DiagonalChecker[2+1];
    //calls and stars col row and diagonal threads
    for(int i = 1; i<=MagicSum.size; i++){
      //the origional square, row/col/diagonal number, and the awnser array are
      //passed to the respective objects for calculations.
      row[i] = new RowChecker(MagicSum.magicSquare,i,awnsArr);
      row[i].start();
      col[i] = new ColumnChecker(MagicSum.magicSquare,i,awnsArr);
      col[i].start();
    }
    for(int i = 1; i<=2; i++){
      diagonal[i] = new DiagonalChecker(MagicSum.magicSquare,i,awnsArr);
      diagonal[i].start();
    }

    //waits for all row and col threads to complete
    for(int i=1;i<=size;i++){
      try {
        row[i].join();
        col[i].join();

      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
    //waits for all diagonal threads to complete
    for(int i=1;i<=2;i++){
      try {
        diagonal[i].join();

      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }

  //prints out results based on the array of awnsers given as a param.
  public static void printResults(int[] awnsArr){
    System.out.println("===   All threads completed   ===");
    System.out.println();

    System.out.println("SUMMARY");
    System.out.println("---------------------------------------");

    //prints thread numbers
    System.out.print("#           |");
    for(int i = 1; i<=((awnsArr.length-2)/2); i++){
      System.out.print("  "+i+"  ");
    }
    System.out.println();

    //prints row sums
    System.out.print("Rows        |");
    for(int i = 0; i<=((awnsArr.length-2)/2)-1; i++){
      System.out.print("  "+awnsArr[i]+"  ");
    }
    System.out.println();

    //prints col sums
    System.out.print("Cols        |");
    for(int i = 0; i<=((awnsArr.length-2)/2)-1; i++){
      System.out.print("  "+awnsArr[i+((awnsArr.length-2)/2)]+"  ");
    }
    System.out.println();

    //prints diagonal sums
    System.out.print("Diagonals   |");
    System.out.print("  "+awnsArr[awnsArr.length-1]+"  ");
    System.out.print("  "+awnsArr[awnsArr.length-2]+"  ");

    System.out.println();
    System.out.println();
    System.out.println("----------------");

    System.out.println("~*~*~ Result *~*~*~");

    System.out.println();
    for (int[] row : MagicSum.magicSquare)
      System.out.println(Arrays.toString(row));
    System.out.println();

    //checks if all the awnsers are the same if so its magicly a square.
    boolean maybe = true;
    int magicSum = awnsArr[1];
    for(int i = 0; i<=((awnsArr.length-2)/2)-1; i++){
      if(magicSum==awnsArr[i]){
        maybe = true;
      }
      else
        maybe = false;
    }

    if(maybe==false){
      System.out.println("^ This is not a magic square ^");
    }
    if(maybe==true){
      System.out.println("^ This IS a magic square! ^");
      System.out.println("magic sum = 15");
    }
    System.out.println();

  }


  //a simple function that is passed a file to fill the awnser array
  public static int[][] fillArray(File f){
    try{
      Scanner scan = new Scanner(f);

      int rows = scan.nextInt();
      int cols = rows;
      MagicSum.size = rows;
      int [][] magicSquare = new int[rows][cols];

      for(int i = 0; i<rows; i++){
        String [] line = scan.nextLine().trim().split(" ");
        for(int j = 0; j<cols; j++){
          magicSquare[i][j] = scan.nextInt();
        }
      }
      return magicSquare;
    }

    //file does not exsist
    catch(FileNotFoundException e){
      System.out.println("File DNE!");
      System.exit(0);
    }

    return null;

  }
}
