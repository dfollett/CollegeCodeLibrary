/*
* This is the Message class. It has a constructor for message (string from
* buffer). has setTerminate() to use to set the message to "".
* isterminate returns bool if has terminate or not. toString returns String
* or terminate equivallent.
*
* @author  Dustin Follett
* @since   11-30-19
*/

class Message {
  public String message;
  public boolean terminate;

  Message(String message){
    this.message = message;
    this.terminate = false;
  }


  public void setTerminate(){
    message = "";
    terminate = true;
  }

  public boolean isTerminate(Message message){
    if(message.toString().equals("Quitter : True")){
      setTerminate();
      return true;
    }
    else{
      return false;
    }
  }

  public String toString(){
    if(message.equals("terminate")){
      return "Quitter : True";
    }
    else
      return message;
  }

}
