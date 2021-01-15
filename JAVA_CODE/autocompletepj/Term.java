/*
* This is the API for Autocomplete which also contains
* the two comparators SortByRevWeight and SortByPref.
* There is also a toString to format the output.
*
* @author  Dustin Follett
* @since   3-5-19
*/


import java.util.Comparator;
import java.lang.String;

public class Term implements Comparable<Term> {

  private String query;
  private Long weight;

    // Initializes a term with the given query string and weight.
    public Term(String query, long weight){
      if(query.equals(null) || query.equals("") || weight < 0){
        throw new NullPointerException("The argument must be a string or char.");
      }
      this.query = query;
      this.weight = weight;
    }

    //Annonymous class for sorting by weight reversed.
    public static Comparator<Term> SortByRevWeight(){
      return new Comparator<Term>(){
        // Compares the two terms in descending order by weight.
        @Override
        public int compare(Term t1,Term t2){
          return (t2.weight.compareTo(t1.weight));
        }
      };
    }

    //Annonymous class for sorting by a prefix of k
    //as passed in by the Autocomplete class.
    public static Comparator<Term> SortByPref(int r){
      return new Comparator<Term>(){
        // Compares the two terms in lexicographic order
        // but using only the first r characters of each query.
      @Override
        public int compare(Term t1,Term t2){
          if(t1.query.length() < r){
            int len = t1.query.length();
            return (t1.query.substring(0, len)).compareToIgnoreCase(t2.getQuery().substring(0, len));
          }
          else{
            return (t1.query.substring(0, r)).compareToIgnoreCase(t2.getQuery().substring(0, r));
        	}
        }
      };
    }

    // Compares the two terms in lexicographic order by query.
    public int compareTo(Term that){
      return (this.getQuery().compareTo(that.getQuery()));
    }

    //getters
    public String getQuery(){
      return query;
    }

    public long getWeight(){
      return weight;
    }

    // Returns a string representation of a Term
    public String toString(){
      return new String(weight + " " + query);
    }
}
