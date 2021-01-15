/*
* Percolation class
*
* This is the percolation class utilized by PercolationVisualizer which reads from a text file. Percolation.java contains methods for checking
* if the grid will percolate. The Visualizer displays closed squares as black open as white and filled as blue. Also Percolation has an optional 
* main class for testing the methods individually. when ran it will print to the console what is being linked using the union method 
* provided by WeightedQuickUnionUF.
*
* @author  Dustin Follett
* @since   1-19-19
*/



import edu.princeton.cs.algs4.WeightedQuickUnionUF;
import edu.princeton.cs.algs4.StdOut;

public class Percolation {

	/*
	* instance variables.
	*/
    private WeightedQuickUnionUF unionFinder;

    private int gridSize = 0;
    private int start = 0;
	private int count = 0;
	private boolean[][] gridOpenTF;
	private boolean TF;

	/*
	* percolation constructor.
	*/
    public Percolation(int n) { 				// create n­by­n grid, with all sites blocked
        gridSize = n;							//initalizes n to the inputed number
		count = 0;
        unionFinder = new WeightedQuickUnionUF(n * n + 2);	//creates linear array n*n in
		gridOpenTF = new boolean [n][n];					//initalizes n*n grid of squares Bool length
		TF = false;								//initalizes tf for percolates method
    }

	/*
	* method to validate the inputed cordinates from text file. Then checks if the square at that coordinate is open or not.
	* Next it links all the squares that are within 1 proximity to eachother in four directions.
	*/
    public void open(int row, int col) {		//open site (row, col) if not open already
		validate(row-1);						//validator w/in grid size
		validate(col-1);						//validator w/in grid size

		if (gridOpenTF[row-1][col-1] = false)	//checks if space is open	
			gridOpenTF[row-1][col-1] = true;
		else	
			gridOpenTF[row-1][col-1] = true;

		if (row > 1 && isOpen(row - 1, col)){					//unions top to bottom
			unionFinder.union(xyTo1D(row,col),xyTo1D(row - 1,col));
			StdOut.print("connecting top node :" + "(" + (row - 1) + " , " + col + ")" + "  to bottom node :" + "(" + row + " , " + col + ")\n");
		}

		if (row < gridSize && isOpen(row + 1, col)){         	//unions bottom to top
			unionFinder.union(xyTo1D(row,col),xyTo1D(row + 1,col));
			StdOut.print("connecting bottom node :" + "(" + (row + 1) + " , " + col + ")" + "  to top node :" + "(" + row + " , " + col + ")\n");
		}

		if (col > 1 && isOpen(row, col - 1)){     				//unions left to right	
			unionFinder.union(xyTo1D(row,col),xyTo1D(row,col - 1));
			StdOut.print("connecting left node :" + "(" + row + " , " + (col - 1) + ")" + "  to right node :" + "(" + row + " , " + col + ")\n");
		}
	
		if (col < gridSize && isOpen(row, col + 1)){     		//unions right to left
			unionFinder.union(xyTo1D(row,col),xyTo1D(row,col + 1));
			StdOut.print("connecting right node :" + "(" + row + " , " + (col + 1) + ")" + "  to left node :" + "(" + row + " , " + col + ")\n");
		}
    }

	/*
	* converts the 2D array into 1D when called.
	*/
	private int xyTo1D(int row, int col){
		return (row - 1) * gridSize + (col - 1);
	}

	/*
	* validates that the inputed integer is withing the grid.
	*/
    private void validate(int p) {
        if (p < 0 || p >= gridSize) 
            throw new IllegalArgumentException("index " + p + " is not between 1 and " + (gridSize));  
    }

	/*
	* checks of the grid is open at any provided cordinates.
	*/
    public boolean isOpen(int row, int col) {   // is site (row, col) open?
        return gridOpenTF[row - 1][col - 1];	// returns bool
    }

	/*
	* checks if any rows are all opened.
	*/
    public boolean isFull(int row, int col) {   // is site (row, col) full?
        if(isOpen(row,col) == true){
			for(int i = 0; i < gridSize; i++){	//ittrs the y axis
				if(unionFinder.connected(xyTo1D(row,col),i)) 
					return true;

			}
		}
		return false;
    }

	/*
	* simple method to itterate and count all open spaces in the grid.
	*/
    public int numberOfOpenSites() {            // number of open sites
		for(int i = 0; i < gridSize; i++){		//itterator through i & j
			for(int j = 0; j < gridSize; j++){
				if (gridOpenTF[i][j] == true)	//checks if open
					return count++;
			}	
		}
		return count += 1;
    }

	/*
	* handles case when the grid size is one. Also lets PercolationVisualizer know if the grid percolates or not.
	* Does this by checking if any rows are a straight shot to the bottom otherwise it will itterate any unions till it reaches the bottom.
	*/
	public boolean percolates() {              // does the system percolate?

		if (gridSize == 1 && isOpen(1,1) == true) TF = true;	//handles input1

		for (int i = (gridSize * gridSize)-1; i < (gridSize * gridSize); i ++){ //everyhting else
			for (int j = 1; j < gridSize; j++){									
				if(unionFinder.connected(i,j)) TF = true;		//if no full vert row

				if (isFull(gridSize, j)) TF = true;				//if vert row full perc always
			}
		}
		return TF;
	}

	/*
	* optional main method to test methods within percolation.
	*/
    public static void main(String[] args) { }  // test client (optional)
}




