package cs251lab10package;

import java.net.*;
import java.io.*;
import java.util.*;
import java.text.*;


public class JChatComm {



public int sendMessage(Socket Sock,ClientEnc ce) throws Exception
{
	String s,stime;
	PrintStream send = new PrintStream(Sock.getOutputStream());
	DataOutputStream dOut = new DataOutputStream(Sock.getOutputStream());
	Scanner insend = new Scanner(System.in);
	System.out.println("Give Message to send to server:");
	s=insend.nextLine();

	
	Date date = new Date();
    SimpleDateFormat sdf = new SimpleDateFormat("MM/dd/yyyy h:mm:ss a");
	stime= sdf.format(date);

//	byte[] arr=ce.encrypt(s);
	send.println(s);
	send.println(stime);
	//System.out.println("done "+arr.length);
	//dOut.writeInt(arr.length); // write length of the message
	//dOut.write(arr); 
	return endChat(s);
	
}

public int endChat(String s) throws Exception
{  //System.out.println("call");
	if(s.equals("ENDCHAT"))
	{
		return 1;
	}
	return 0;
	
}
public void receiveMessage(Socket Sock,ClientEnc ce) throws Exception
{
	BufferedReader reader = new BufferedReader(new InputStreamReader(Sock.getInputStream()));
	String s,stime;
	s=reader.readLine();
	//s=ce.decrypt(s.getBytes());
	stime=reader.readLine();
	System.out.println(s);
	System.out.println(stime);
	return ;
}


}
