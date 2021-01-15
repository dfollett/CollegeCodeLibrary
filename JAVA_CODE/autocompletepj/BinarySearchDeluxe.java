/*
* This is the BinarySearchDeluxe Class it contains
* two methods one to binarily search an array to
* find the first index and another to find the
* last index.
*
* @author  Dustin Follett
* @since   1-19-19
*/


import java.util.Comparator;

public class BinarySearchDeluxe {

    // Returns the index of the first key in a[] that equals the search key,
    // or ­1 if no such key.
    public static <Term> int firstIndexOf(Term[] a, Term key, Comparator<Term>
comparator){
      int lo = 0;
      int hi = a.length;

      while(lo + 1 != hi) {
        // Key is in myArray[lo..hi] or not present.
        int mid = lo + (hi - lo) / 2;
        if(comparator.compare(a[mid], key) < 0)
          lo = mid­;
        else
          hi = mid;
      }
      return hi;
    }

    // Returns the index of the last key in a[] that equals the search key,
    // or ­1 if no such key.
    public static <Term> int lastIndexOf(Term[] a, Term key, Comparator<Term>
comparator){
      int lo = 0;
      int hi = a.length;

      while(lo + 1 != hi) {
        // Key is in myArray[lo..hi] or not present.
        int mid = lo + (hi - lo) / 2;
        if(comparator.compare(a[mid], key) > 0)
          hi = mid­;
        else
          lo = mid;
      }
      return lo;
    }
}
