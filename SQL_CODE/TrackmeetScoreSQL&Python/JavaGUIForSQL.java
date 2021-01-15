// java interface for the sql database. Inserts new athletes, new results, dqs player for either event or whole meet,
// also dqs a player if they participate in too many events via trigger,
// prints out the results of one event, scores an event, and lastly very crudely scores the events because 
// I had a nightmare trying to get the store the points as well as with the whole project, but it works mostly. I probably spent
// well over 30 hours on this.

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.CallableStatement;
import java.sql.Types;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.*;
import java.sql.PreparedStatement;

public class FollettP4 {

// sets up all the parameters to connect to database
    private static String hostname = "csdb.cs.eou.edu";
    private static String port = "3306";
    private static String database = "dbFollettTrack";
    private static String database2 = "dbFollett";
    private static String user = "dfollett";
    private static String password = "910211457";
    private static String flags = "?noAccessToProcedureBodies=true";
    
    private Scanner input = new Scanner(System.in);

//main method calls the start menu method where everything is handled
	public static void main(String args[]) throws Exception {
		FollettP4 start = new FollettP4();
		while (true)
			start.startMenu();
	}
	

//handles all user input and output
	public void startMenu(){
	//display menu for reffs to interact
		System.out.println("Please Select An Option Below: \n"+
		"1: To add a new Athlete\n"+
		"2: To enter a new result\n"+
		"3: To get the results for an event\n"+ 
		"4: To score an event\n"+
		"5: To disqualify an athlete for one event\n"+ 
		"6: To disqualify an athlete for the meet\n"+ 
		"7: To score the meet\n"+
		"8: TO QUIT\n"+ 
		"Enter number: ");
		
		// grabs thier input
		int selection = input.nextInt();
		input.nextLine();
		
		//switch stmt handling what option they choose		
		switch (selection){
		//for entering an athlete asks questions and stores input
			case 1:
				System.out.println("\nEnter the competitor's first name: \n");
				String firstName = input.nextLine();
				
				System.out.println("Enter the competitor's last name: \n");
				String lastName = input.nextLine();
			
				System.out.println("Enter the competitor's gender (M or F): \n");
				String gender = input.nextLine();
				
				System.out.println("Enter the competitor's School ID: \n");
				int schoolId = input.nextInt();
				
				System.out.println("\n");
				
				System.out.println("First Name is: "+firstName);
				System.out.println("Last Name is: "+lastName);
				System.out.println("competitor gender is: "+gender);
				System.out.println("School Id is : "+schoolId);
				
				System.out.println("\n");
				
				// double checks you put in the right information before commiting
				System.out.println("Please Select An Option Below: \n"+
				"9: If these inputs are correct and you wish to commit.\n"+
				"10: If you messed up and would like to re-input\n"+ 
				"Enter number: ");
				
				int insAthlete = input.nextInt();
				input.nextLine();
					
				switch (insAthlete){
					case 9:	
						try {
							Connection conn = DriverManager.getConnection("jdbc:mysql://"
								+ hostname + "/" + database + flags, user, password);	
							Statement stmt = conn.createStatement();
							
							//calls first of many stored procedures
							CallableStatement cStmt = conn.prepareCall("{call enterAthlete(?,?,?,?)}");
							
							cStmt.registerOutParameter(1,Types.VARCHAR); 
							cStmt.registerOutParameter(2,Types.VARCHAR);
							cStmt.registerOutParameter(3,Types.VARCHAR);
							cStmt.registerOutParameter(4,Types.INTEGER); 
							
							cStmt.setString(1,firstName);
							cStmt.setString(2,lastName);
							cStmt.setString(3,gender);
							cStmt.setInt(4,schoolId);
							      
							cStmt.execute();
							System.out.println("Entering Athlete...\n" );
							
							conn.close();
							break;
						
						//catches errors prints stack trace					
						} catch (SQLException ex) {
							System.out.println("SQLException: " + ex.getMessage());
							System.out.println("SQLState: " + ex.getSQLState());
							System.out.println("VendorError: " + ex.getErrorCode());
							ex.printStackTrace();
							break;
						}
						
					case 10:
						break;
					
					default:
						System.out.println("Invalid selection input try again.\n");
						break;
				}
				break;
				
			// handles input of results	
			case 2:
				System.out.println("Enter the competitor's result:\n");
				String result = input.nextLine();
				
				System.out.println("\nEnter the competitor's number:\n");
				int number = input.nextInt();
				
				System.out.println("Enter the events's Id:\n");
				int eventId = input.nextInt();
				
				System.out.println("\n");
				
				System.out.println("competitor ID is: "+number);
				System.out.println("Event ID is: "+eventId);
				System.out.println("competitor result is : "+result);
				
				System.out.println("\n");
				
				System.out.println("Please Select An Option Below: \n"+
				"9: If these inputs are correct and you wish to commit.\n"+
				"10: If you messed up and would like to re-input\n"+ 
				"Enter number: ");
				
				System.out.println("\n");
				
				int insResult = input.nextInt();
				input.nextLine();
					
				switch (insResult){
					case 9:	
						try {
							Connection conn = DriverManager.getConnection("jdbc:mysql://"
								+ hostname + "/" + database + flags, user, password);	
							Statement stmt = conn.createStatement();
							
							CallableStatement cStmt = conn.prepareCall("{call enterResult(?,?,?)}");
							cStmt.registerOutParameter(1,Types.INTEGER); 
							cStmt.registerOutParameter(2,Types.INTEGER);
							cStmt.registerOutParameter(3,Types.VARCHAR);
							
							cStmt.setInt(1,number);
							cStmt.setInt(2,eventId);
							cStmt.setString(3,result);
   				
							System.out.println("Entering Result...\n" );      
							cStmt.execute();
							
							conn.close();
							break;
											
						} catch (SQLException ex) {
							System.out.println("SQLException: " + ex.getMessage());
							System.out.println("SQLState: " + ex.getSQLState());
							System.out.println("VendorError: " + ex.getErrorCode());
							ex.printStackTrace();
							break;
						}
						
					case 10:
						break;
					
					default:
						System.out.println("Invalid selection input try again.\n");
						break;
				}
				break;
			
			//prints specific event
			case 3:
				try {
					Connection conn = DriverManager.getConnection("jdbc:mysql://"
						+ hostname + "/" + database + flags, user, password);

					Statement stmt = conn.createStatement();
					System.out.println("\nEnter the Event Id to see results: \n");
					String eventNumber = input.nextLine();
					
					boolean gotResults = stmt.execute("SELECT * from Results r where EventID = "+eventNumber+" ORDER BY Place ASC;");

					ResultSet rs = stmt.getResultSet(); 	
					rs.first();					
					
					System.out.printf("| %-20s | %-20s | %-20s | %-20s| %-20s | %-20s | %-20s | %-20s | %-20s |","Place","First","Last","EventID","Event","Result","Points","School","Disqualified");
					System.out.println("\n===============================================================================================================================================================================================================");
					
					// pulls all data from table
					while (gotResults) {
						int place = rs.getInt("Place");
						String first = rs.getString("First");
						String last = rs.getString("Last");
						int eventIds = rs.getInt("EventId");
						String eventName = rs.getString("Event");						
						Float results = rs.getFloat("Result");
						int points = rs.getInt("Points");						
						String school = rs.getString("School");
						String dqed = rs.getString("Disqualified");
						System.out.printf("| %-20s | %-20s | %-20s | %-20s| %-20s | %-20.2f | %-20s | %-20s | %-20s |",place,first,last,eventIds,eventName,results,points,school,dqed);
						System.out.println("\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");						
												
						gotResults = rs.next();
					}
					
		    		conn.close();

			} catch (SQLException ex) {
				System.out.println("SQLException: " + ex.getMessage());
				System.out.println("SQLState: " + ex.getSQLState());
				System.out.println("VendorError: " + ex.getErrorCode());
				ex.printStackTrace();
			}
				break;
			
			// scores one event using stored procedure	
			case 4:
				System.out.println("\nEnter the EventId in which youd like to score:\n");
				int eventNumber = input.nextInt();
				
				System.out.println("DQ competitor ID is: "+eventNumber);
				
				System.out.println("\n");
				
				System.out.println("Please Select An Option Below: \n"+
				"9: If these inputs are correct and you wish to commit.\n"+
				"10: If you messed up and would like to re-input\n"+ 
				"Enter number: ");
				
				System.out.println("\n");
				
				int scoreEvent = input.nextInt();
				input.nextLine();
					
				switch (scoreEvent){
					case 9:	
						try {
							Connection conn = DriverManager.getConnection("jdbc:mysql://"
								+ hostname + "/" + database + flags, user, password);	
							Statement stmt = conn.createStatement();
							
							String query = "SELECT * FROM Eventss where eventId = "+eventNumber+" ;";
							ResultSet rs = stmt.executeQuery(query);
							rs.first();
							String resultType = rs.getString("eventType");
							
							//scores field event
							if(resultType.toString().equals("Field")){
								CallableStatement cStmt = conn.prepareCall("{call scoreField(?)}");
								cStmt.registerOutParameter(1,Types.INTEGER); 
								
								cStmt.setInt(1,eventNumber);
								System.out.println("Scored the Event use option 3 or 7 to see results...\n" );    
								cStmt.execute();
								}

							//scores track event
							if (resultType.toString().equals("Track")){
								CallableStatement CStmt = conn.prepareCall("{call scoreTrack(?)}");
								CStmt.registerOutParameter(1,Types.INTEGER); 
							
								CStmt.setInt(1,eventNumber);
							
								System.out.println("Scored the Event use option 3 or 7 to see results...\n" );      
								CStmt.execute();
								}
							
							conn.close();
							break;
   				
											
						} catch (SQLException ex) {
							System.out.println("SQLException: " + ex.getMessage());
							System.out.println("SQLState: " + ex.getSQLState());
							System.out.println("VendorError: " + ex.getErrorCode());
							ex.printStackTrace();
							break;
						}
						
					case 10:
						break;
					
					default:
						System.out.println("Invalid selection input try again.\n");
						break;
				}
				break;
			
			// dq athlete from one event	
			case 5:
				System.out.println("\nEnter the Dqed competitor's number:\n");
				int dqenumber = input.nextInt();
				
				System.out.println("Enter the dq events's Id:\n");
				int dqeeventId = input.nextInt();
				
				System.out.println("DQ competitor ID is: "+dqenumber);
				System.out.println("DQ Event ID is: "+dqeeventId);
				
				System.out.println("\n");
				
				System.out.println("Please Select An Option Below: \n"+
				"9: If these inputs are correct and you wish to commit.\n"+
				"10: If you messed up and would like to re-input\n"+ 
				"Enter number: ");
				
				System.out.println("\n");
				
				int changeDQEvent = input.nextInt();
				input.nextLine();
					
				switch (changeDQEvent){
					case 9:	
						try {
							Connection conn = DriverManager.getConnection("jdbc:mysql://"
								+ hostname + "/" + database + flags, user, password);	
							Statement stmt = conn.createStatement();
							
							CallableStatement cStmt = conn.prepareCall("{call DqEvent(?,?)}");
							cStmt.registerOutParameter(1,Types.INTEGER); 
							cStmt.registerOutParameter(2,Types.INTEGER);
							
							cStmt.setInt(1,dqenumber);
							cStmt.setInt(2,dqeeventId);
   				
							System.out.println("DQing Athlete in the specified event...\n" );      
							cStmt.execute();
							
							conn.close();
							break;
											
						} catch (SQLException ex) {
							System.out.println("SQLException: " + ex.getMessage());
							System.out.println("SQLState: " + ex.getSQLState());
							System.out.println("VendorError: " + ex.getErrorCode());
							ex.printStackTrace();
							break;
						}
						
					case 10:
						break;
					
					default:
						System.out.println("Invalid selection input try again.\n");
						break;
				}
				break;
			
			// dqs athlete from whole meet
			case 6:
				System.out.println("\nEnter the Dqed competitor's number:\n");
				int dqmnumber = input.nextInt();
				
				System.out.println("DQ competitor ID is: "+dqmnumber);
				
				System.out.println("\n");
				
				System.out.println("Please Select An Option Below: \n"+
				"9: If these inputs are correct and you wish to commit.\n"+
				"10: If you messed up and would like to re-input\n"+ 
				"Enter number: ");
				
				System.out.println("\n");
				
				int changeDQMeet = input.nextInt();
				input.nextLine();
					
				switch (changeDQMeet){
					case 9:	
						try {
							Connection conn = DriverManager.getConnection("jdbc:mysql://"
								+ hostname + "/" + database + flags, user, password);	
							Statement stmt = conn.createStatement();
							
							CallableStatement cStmt = conn.prepareCall("{call DqMeet(?)}");
							cStmt.registerOutParameter(1,Types.INTEGER); 
							
							cStmt.setInt(1,dqmnumber);
   				
							System.out.println("DQing Athlete in the Meet...\n" );      
							cStmt.execute();
							
							String query1 = "SELECT FirstName from Athlete where athId = "+dqmnumber+" ;";
							ResultSet rs1 = stmt.executeQuery(query1);
							rs1.first();
							String first = rs1.getString("FirstName");
							
							String query = "SELECT * FROM Athlete where athId = "+dqmnumber+" ;";
							ResultSet rs = stmt.executeQuery(query);
							rs.first();
							String resultType0 = rs.getString("athTooManyEventsDqed");
							
							String query3 = "SELECT eventId from Results where First = '"+first+"' ;";
							ResultSet rs3 = stmt.executeQuery(query3);
							rs3.first();
							int evNumber = rs3.getInt("eventId");
						
							//if dqed in athlete will also dq in all events participated in
							if (resultType0.toString().equals("True")){
								CallableStatement dStmt = conn.prepareCall("{call DqEvent(?,?)}");
								dStmt.registerOutParameter(1,Types.INTEGER); 
								dStmt.registerOutParameter(2,Types.INTEGER);
								
								dStmt.setInt(1,dqmnumber);
								dStmt.setInt(2,evNumber);
								dStmt.execute();
							}	
							
							conn.close();
							break;
											
						} catch (SQLException ex) {
							System.out.println("SQLException: " + ex.getMessage());
							System.out.println("SQLState: " + ex.getSQLState());
							System.out.println("VendorError: " + ex.getErrorCode());
							ex.printStackTrace();
							break;
						}
						
					case 10:
						break;
					
					default:
						System.out.println("Invalid selection input try again.\n");
						break;
				}
				break;
			
			// very rudamentary scores and displays school results 	
			case 7:
				try {
					Connection conn = DriverManager.getConnection("jdbc:mysql://"
						+ hostname + "/" + database + flags, user, password);	
					Statement stmt = conn.createStatement();
					
					boolean query1 = stmt.execute("SELECT COUNT(DISTINCT eventId) from Eventss");
					ResultSet rs = stmt.getResultSet();
					rs.first();
					int a =  ((Number) rs.getObject(1)).intValue();	
	
					//loops through each event to score
					while(a>0){
					
						System.out.println("scoring this event: "+a);
								
						String query = "SELECT eventType FROM Eventss where eventId = "+a+" ;";
						ResultSet rs1 = stmt.executeQuery(query);
						rs1.first();
						String resultType = rs1.getString("eventType");
						
						if(resultType.toString().equals("Field")){
							CallableStatement cStmt = conn.prepareCall("{call scoreField(?)}");
							cStmt.registerOutParameter(1,Types.INTEGER); 
							
							cStmt.setInt(1,a);
   
							cStmt.execute();
							}

						else if (resultType.toString().equals("Track")){

							CallableStatement CStmt = conn.prepareCall("{call scoreTrack(?)}");
							CStmt.registerOutParameter(1,Types.INTEGER); 
						
							CStmt.setInt(1,a);
						    
							CStmt.execute();					
							}
							
							query1 = rs1.next();
							a = a-1;

					}
					
					boolean query2 = stmt.execute("SELECT COUNT(DISTINCT schoolId) from School");
					ResultSet rs2 = stmt.getResultSet();
					rs2.first();
					int b =  ((Number) rs2.getObject(1)).intValue();
					
					int school1 = 0;
					int school2 = 0;
					int school3 = 0;
					int school4 = 0;
					int school5 = 0;
					
					//loops through each school then all results adding their respective scores
					while (b>0){
						
						boolean query3 = stmt.execute("SELECT COUNT(resultId) from Results");
						ResultSet rs3 = stmt.getResultSet();
						rs3.first();
						int c =  ((Number) rs3.getObject(1)).intValue();
						int points = 0;
							
						while (c>0){
						
							boolean query4 = stmt.execute("SELECT points from Results where resultId = "+b+" ;");
							ResultSet rs4 = stmt.getResultSet();
							rs4.first();
							int d =  ((Number) rs4.getObject(1)).intValue();
							
							points = points + d;
							
							if(b==1){
								school1 = school1 + d;
							}
							if(b==2){
								school2 = school2 + d;
							}
							if(b==3){
								school3 = school3 + d;
							}
							if(b==4){
								school4 = school4 + d;
							}
							if(b==5){
								school5 = school5 + d;
							}

							c = c-1;

						}

						b = b-1;
						
						boolean query5 = stmt.execute("SELECT * from School where schoolId = "+(b+1)+";");
						ResultSet rs5 = stmt.getResultSet();
						rs5.first();
						String d =  rs5.getString("schoolName");
						//prints results
						//for some reason one of the schools doesnt score correctly but the others do??????????
						System.out.println("\npoints for school id "+d+" = "+points+"\n");	
						

					}
					break;
		
									
				} catch (SQLException ex) {
					System.out.println("SQLException: " + ex.getMessage());
					System.out.println("SQLState: " + ex.getSQLState());
					System.out.println("VendorError: " + ex.getErrorCode());
					ex.printStackTrace();
					break;
				}
				
				case 10:
					break;
			
				default:
					System.out.println("Invalid selection input try again.\n");
					break;

			case 8:
				System.out.println("Exiting....");
				System.exit(1);
			}
	}
	
}
