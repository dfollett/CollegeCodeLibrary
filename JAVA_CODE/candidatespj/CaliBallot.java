
import edu.princeton.cs.algs4.In;
import java.util.Collections;
import edu.princeton.cs.algs4.Insertion;
import edu.princeton.cs.algs4.Selection;
import edu.princeton.cs.algs4.Stopwatch;

/**
*<p>This is CaliBallot where all the inputs are validated first. Then a sort is preformed and timed after which it prints to the console the results. </p>
*
*@see CaliCandidate
*/
public class CaliBallot{

	/**
	*This is the main method which makes use of validation methods to sort based on the users input. Args are sort name, sort criteria, and path.
	*/
	public static void main(String[] args){
		validateArgs(args);
		String sortName = args[0];
		String sortCriteria = args[1];
		String path = args[2];
		validatePath(path);
		validateAndSort(sortName, sortCriteria, path);
	}

	/**
	*ValidateArgs is a method to validate that there is the correct number of arguments. If not enough args are entered the program prints a usage message and closes.
	*/
	public static void validateArgs(String[] args){
		if (args.length < 3){
			usage();
			System.exit(0);
		}
	}

	/**
	*ValidatePath is a method that validates the user inputed file path. If not found an error is thrown sugesting a possible error and fix. Then it exits. 
	*
	*@param path the user inputed path to the file containing the candidate info.
	*@throws general @Exception if the file does not exsist.
	*/
	public static void validatePath(String path){
		try{
			In in = new In(path);
		}
		catch (Exception e){
			System.out.println("File not found!");
			System.exit(0);
		}
	}

	/**
	*Candidate method constructor makes an object with first and last name, age, and party. It also reads from the user file and parses accordingly. Then it returns an array of candidates.
	*
	*@param path First param path the user inputed path.
	*@param sortName Second param user inputed sort name.
	*@param sortCriteria Third param user inputed sort criteria.
	*@return Candidate[] returns all the objects in an array called CaliCandidate.
	*/
	public static CaliCandidate[] candidate(String path, String sortName, String sortCriteria){

			In in = new In(path);
			String[] lines = in.readAllLines();
			CaliCandidate[] candidates = new CaliCandidate[lines.length];

			for (int i = 1; i < lines.length; i++){
				String[] tokens = lines[i].split(",");
				String firstName = tokens[0].trim();
				String lastName = tokens[1].trim();
				int age = Integer.parseInt(tokens[2].trim());
				String party = tokens[3].trim();
				candidates[i] = new CaliCandidate(firstName, lastName, age, party);
			}
			return candidates;
	}

	/**
	*ValidateAndSort method navigates through if statements to decide which sort name to use then passes it to the correct method. If the name is spelled wrong it prints an error.
	*
	*@param sortName First param the user inputed sort name.
	*@param sortCriteria Second param the user inputed sort criteria.
	*@param path Third param the user inputed path.
	*/
	public static void validateAndSort(String sortName, String sortCriteria, String path){
		if (sortName.equals("Selection")){
			System.out.println("you picked Selection sort.");
			sortTypeSel(sortName, sortCriteria, path);
		}
		else if (sortName.equals("Insertion")){
			System.out.println("you picked Insertion sort.");
			sortTypeIns(sortName, sortCriteria, path);
		}
		else{
			System.out.println("Check the spelling and capitalization of your Sort Type argument.\n it should be Selection or Insertion.");
			System.exit(0);
		}
	}

	/**
	*sortTypesel is the Selection sort classification once here depending on the input the file is read using candidate method. Then it times and sorts the candidates and finnaly prints 		*them out.
	*
	*@param sortName First param sort name user inputed sort name.
	*@param sortCriteria Second param sort criteria user inputed sort criteria.
	*@param path Third param path the user inputed path.
	*/
	public static void sortTypeSel(String sortName, String sortCriteria, String path){
		if (sortCriteria.equals("FirstName")){
			System.out.println("you picked to sort by First Name.");
			CaliCandidate[] candidates = candidate(path, sortName, sortCriteria);
			SortByFirst sortFirst = new SortByFirst();
        	Stopwatch timer = new Stopwatch();
			Selection.sort(candidates, sortFirst);
			toString(candidates,timer);	
		}

		else if (sortCriteria.equals("LastName")){
			System.out.println("you picked to sort by Last Name.");
			CaliCandidate[] candidates = candidate(path, sortName, sortCriteria);
			SortByLast sortLast = new SortByLast();
        	Stopwatch timer = new Stopwatch();
			Selection.sort(candidates, sortLast);
			toString(candidates,timer);	
		}

		else if (sortCriteria.equals("Default")){
			System.out.println("you picked to sort by Default.");
			CaliCandidate[] candidates = candidate(path, sortName, sortCriteria);
			SortByDefault sortDefault = new SortByDefault();
        	Stopwatch timer = new Stopwatch();
			Selection.sort(candidates, sortDefault);
			toString(candidates,timer);
		}

		else{
			System.out.println("check the spelling and capitalization of your Sort Criteria argument. it should be FirstName, LastName, or Default");
			System.exit(0);
		}
	}

	/**
	*sortTypeIns is the Insertion sort classification once here depending on the input the file is read using candidate method. Then it times and sorts the candidates and finnaly prints 		*them out.
	*
	*@param sortName First param the user inputed sort name.
	*@param sortCriteria Second param the user inputed sort criteria.
	*@param path Third param the user inputed path.
	*/
	public static void sortTypeIns(String sortName, String sortCriteria, String path){
		if (sortCriteria.equals("FirstName")){
			System.out.println("you picked to sort by First Name.");
			CaliCandidate[] candidates = candidate(path, sortName, sortCriteria);
			SortByFirst sortFirst = new SortByFirst();
        	Stopwatch timer = new Stopwatch();
			Insertion.sort(candidates, sortFirst);
			toString(candidates,timer);	
		}

		else if (sortCriteria.equals("LastName")){
			System.out.println("you picked to sort by Last Name.");
			CaliCandidate[] candidates = candidate(path, sortName, sortCriteria);
			SortByLast sortLast = new SortByLast();
        	Stopwatch timer = new Stopwatch();
			Insertion.sort(candidates, sortLast);
			toString(candidates,timer);	
		}

		else if (sortCriteria.equals("Default")){
			System.out.println("you picked to sort by Default.");
			CaliCandidate[] candidates = candidate(path, sortName, sortCriteria);
			SortByDefault sortDefault = new SortByDefault();
        	Stopwatch timer = new Stopwatch();
			Insertion.sort(candidates, sortDefault);
			toString(candidates,timer);
		}

		else{
			System.out.println("check the spelling and capitalization of your Sort Criteria argument. it should be FirstName, LastName, or Default");
			System.exit(0);
		}
	}

	/**
	*Simple toString method to print the sorted candidates and the time it took to do so.
	*
	*@param candidates First param CaliCandidate[] of candidate objects.
	*@param timer Second param stopwatch object for timer.
	*/
    public static void toString(CaliCandidate[] candidates, Stopwatch timer){ 
		for (int i = 1; i < candidates.length; i++){
			System.out.printf("%.09s" + ", " + "%.09s" + ", " + "%d" + ", " + "%.06s\n", candidates[i].getFirstName(), candidates[i].getLastName(), candidates[i].getAge(), candidates[i].getParty());
		}
		System.out.println("elapsed time for sort is: " + timer.elapsedTime() + " seconds.");
    }

	/**
	*Simple usage method to print out the usage message
	*/	
	public static void usage(){
		System.out.println("Usage: Requires 3 arguments. One is sort type. Two is sort criteria. Three is     input text file.\n EX) java -cp .:algs4 CaliBallot Selection FirstName candidates.txt ");
	} 
	
}


