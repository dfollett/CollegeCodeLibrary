
import java.util.Comparator;

/**
*<p>This is the SortByLast name comparator it is a subclass of CaliCandidate and its called if the *user decides to sort by Last name. It sorts based on the order defined as r,w,q,o,j,m,v,a,h,b,s,g,z,x,n,t,c,i,e,k,u,p,d,y,f,l .</p>
*
*@see CaliCandidate
*/
public class SortByLast implements Comparator<CaliCandidate>{

	/**
	*This method is the overridden method compare that returns the integer based on comparisons to the user defined order and then eachother.
	*@param c1 is a candidate passed by sort to be compared.
	*@param c2 is a candidate passed by sort to be compared.
	*@return int retVal either 1, -1, or 0 based on the comparison.
	*/
	@Override
	public int compare(CaliCandidate c1, CaliCandidate c2){
		String order = "rwqojmvahbsgzxntciekupdyfl"; //"RWQOJMVAHBSGZXNTCIEKUPDYFL"
		int comp1 = 0;
		int comp2 = 0;
		int retVal = 0;

		if (c1 == null || c2 == null)
			return 0;	

		if (c1.getLastName().charAt(0) == c2.getLastName().charAt(0)){
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

}
