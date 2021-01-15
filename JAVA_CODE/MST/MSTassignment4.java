/*
* This is the MSTassignment4 class. It uses files from
* Princetons algs 4 jar file to input a user defined
* file then it finds the Minimum spanning Tree.
* the vertex numbers coordinate to city names and weights
* are miles between citys.
* 0 = Summer-Ville
* 1 = Elgin
* 2 = Imbler
* 3 = La Grande
* 4 = Island City
* 5 = Cove
* 6 = Union
* 7 = North Powder
* 8 = Baker
*
* @author  Dustin Follett
* @since   3-9-19
*/

import edu.princeton.cs.algs4.DijkstraSP;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.EdgeWeightedDigraph;
import edu.princeton.cs.algs4.DirectedEdge;

//class for finding the MST of a provided file as arg[0]
public class MSTassignment4{
  public static void main(String[] args){
    String fileName = args[0];
    In in = new In(fileName);
    //creates a edge weighted digraph from input file.
    EdgeWeightedDigraph graph = new EdgeWeightedDigraph(new In(args[0]));
    //parses inputted start location
    int start = Integer.parseInt(args[1]);
    //creates minimum search tree using DijkstraSP algorithm.
    DijkstraSP mst = new DijkstraSP(graph, start);
    //prints out the result
    for (int i = 0; i < graph.V(); i++){
      System.out.printf(start + " To " + i + "  ");
      System.out.printf("(%4.2f miles): ", mst.distTo(i));
      if (mst.hasPathTo(i)){
        for (DirectedEdge e : mst.pathTo(i)){
          System.out.print(e + "   ");
        }
      System.out.println();
      }
    }
  }
}
