
import java.util.Comparator;

/**
*<p>This is the SortByDefault age comparator it is a subclass of CaliCandidate and its called if the user decides to sort by age. It sorts in ascending order.</p>
*
*@see CaliCandidate
*/
public class SortByDefault implements Comparator<CaliCandidate>{

	/**
	*This method is the overridden method compare that returns the integer based on age ordered in ascending.
	*@param c1 is a candidate passed by sort to be compared.
	*@param c2 is a candidate passed by sort to be compared.
	*@return int retVal either 1, -1, or 0 based on the comparison.
	*/
	@Override
	public int compare(CaliCandidate c1, CaliCandidate c2){
		String order = "rwqojmvahbsgzxntciekupdyfl";
		int comp1 = 0;
		int comp2 = 0;
		int retVal = 0;

		if (c1 == null || c2 == null){
			return 0;	
		}

		if (c1 == c2){

			for (int i = 0; i < order.length() ; i++){

				if (c1.getLastName().charAt(0) == order.charAt(i))
					comp1 = i;	
			}

			for (int i = 0; i < order.length() ; i++){
				if (c2.getLastName().charAt(0) == order.charAt(i))
					comp2 = i;
			}

			if(comp1 > comp2)
				retVal = 1;
			
			if(comp1 < comp2)
				retVal = -1;
			
			if(comp1 == comp2)
				retVal = 0;

			return (retVal);
		}

		return (c1.compareTo(c2));
	}

}

