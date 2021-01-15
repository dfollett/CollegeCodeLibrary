/*
* This is the Autocomplete class. It constructs
* an array of suggestions called autoList based
* on the users input to the terminal and
* prints them to terminal after enter is hit.
*
* @author  Dustin Follett
* @since   1-19-19
*/


import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.Selection;
import edu.princeton.cs.algs4.Merge;
import java.util.Arrays;

public class Autocomplete{
  Term[] a = new Term[100000];
  // Initializes the data structure from the given array of terms.
    public Autocomplete(Term[] terms){
      a = new Term[terms.length];
      for (int i = 0; i < terms.length ; i++){
        a[i] = terms[i];
        if(a[i].equals(null) || a[i].getQuery().equals("")){
          throw new NullPointerException("The argument must be a string or char.");
        }
      }
    }

    // Returns all terms that start with the given prefix,
    // in descending order of weight.
    public Term[] allMatches(String prefix){

      if(prefix.equals(null) || prefix.equals("")){
        throw new NullPointerException("The argument must be a string or char.");
      }

      Term compareStr = new Term(prefix, 1);
      int k = prefix.length();
      Arrays.sort(a);
      int indexA = BinarySearchDeluxe.firstIndexOf(a, compareStr, Term.SortByPref(k));
      int indexB = BinarySearchDeluxe.lastIndexOf(a, compareStr, Term.SortByPref(k));
      int matches = numberOfMatches(prefix);
      System.out.println("matches: " + matches);
      Term[] autoList = new Term[matches];

      for (int i = indexA; i < indexA + (matches); i++){
          autoList[i - indexA] = a[i];
      }

      Selection.sort(autoList, Term.SortByRevWeight());
      return autoList;
    }

    // Returns the number of terms that start with the given prefix.
    public int numberOfMatches(String prefix){

      if(prefix.equals(null) || prefix.equals("")){
        throw new NullPointerException("The argument must be a string or char.");
      }

      Term compareStr = new Term(prefix, 1);
      int termHits = 0;
      int k = prefix.length();
      int indexA = BinarySearchDeluxe.firstIndexOf(a, compareStr, Term.SortByPref(k));
      int indexB = BinarySearchDeluxe.lastIndexOf(a, compareStr, Term.SortByPref(k));
      termHits = indexB - indexA;
      return termHits + 1;
    }

    public static void main(String[] args){
      // read in the terms from a file
      String filename = args[0];
      In in = new In(filename);
      int N = in.readInt();
      Term[] terms = new Term[N];

      for (int i = 0; i < N; i++) {
          long weight = in.readLong();          // read the next weight
          in.readChar();                         // scan past the tab
          String query = in.readLine();          // read the next query
          terms[i] = new Term(query, weight);    // construct the term
      }

      // read in queries from standard input and print out the top k matching
      //terms
      if (args.length < 2){
        System.out.println("Usage: Requires 2 arguments. One is the filepath. Two is the number of results shown. \n EX) java -cp .:algs4 Autocomplete wiktionary.txt 10");
      }

      int k = Integer.parseInt(args[1]);
      Autocomplete autocomplete = new Autocomplete(terms);

      while (StdIn.hasNextLine()) {
        String prefix = StdIn.readLine();

        if(prefix.equals(null) || prefix.equals("")){
          throw new NullPointerException("The argument must be a string or char.");
        }

        Term[] results = autocomplete.allMatches(prefix);

        for (int j = 0; j < Math.min(k, results.length); j++){
          System.out.println(results[j]);
        }
      }
    }
}
