
import java.util.Comparator;
import java.lang.String; 

/**
*<p>This is the API for CaliBallot. It contains constructors, getters, setters, and an overriden compareTo method from Comparable.</p>
*<b>Author:</b>
* Dustin Follett
*
*@version 100.0
*@author Dustin Follett
*@since 2019-02-10
*/
public class CaliCandidate implements Comparable<CaliCandidate>{

	private String firstName, lastName, party;
	private int age;


	/**
	*constructor sets all values to "" or 0.
	*/
	public CaliCandidate(){
		this.firstName = "";
		this.lastName = "";
		this.age = 0;
		this.party = "";
	}

	/**
	*constructor sets all values to their respective inputs. 
	*
	*@param firstName First param to constructor passes the candidates first name.
	*@param lastName Second param to constructor passes the candidates last name.
	*@param age Third param to constructor passes the candidates age.
	*@param party Fourth param to constructor passes the candidates political party.
	*/
	public CaliCandidate(String firstName, String lastName, int age, String party){
		this.firstName = firstName;
		this.lastName = lastName;
		this.age = age;
		this.party = party;
	}

	/**
	*getter for first name.
	*
	*@return String returns the first name of the candidate.
	*/
	public String getFirstName(){
		return firstName;
	}

	/**
	*getter for last name.
	*
	*@return String returns the last name of the candidate.
	*/
	public String getLastName(){
		return lastName;
	}

	/**
	*getter for age.
	*
	*@return int returns the age of the candidate.
	*/
	public int getAge(){
		return age;
	}

	/**
	*getter for party.
	*
	*@return String returns the party of the candidate.
	*/
	public String getParty(){
		return party;
	}

	/**
	*inherited method from Comparable class. Overriden.
	*
	*@param that a candidate to be compared to the current candidate.
	*@return int the result of the comparison 1,-1, or 0.
	*/
	@Override
	public int compareTo(CaliCandidate that){
		if (this.age > that.age) return 1;
		if (this.age < that.age) return -1;
		if (this.age == that.age) return 0;

		else{return 0;}
	}

	/**
	*inherited method from Comparator class. Overriden.
	*
	*@param obj checks if two things are equal.
	*@return boolean the result of the comparisons.
	*/
    @Override
    public boolean equals(Object obj) {
        if (this == obj)
			return true;
		if (obj == null )	
			return false;
		if (obj.getClass() != this.getClass())
			return false;
		CaliCandidate candidate = (CaliCandidate) obj;
		return (this.getFirstName() == candidate.getFirstName());	
    }
}


