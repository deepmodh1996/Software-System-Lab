package cs251lab10package;

import java.math.BigInteger;
import java.net.*;
import java.io.*;
import java.util.*;

public class JClient {
    ClientEnc ce;
	Socket Sock;
	 
	public static void main(String[] args) throws Exception	{
		JClient CLIENT = new JClient();
		CLIENT.run();
	}
	public void run() throws Exception
	{
		if(callServer()==1)
		{
			JChatComm chat=new JChatComm();
			System.out.println("senmessage");
		while(chat.sendMessage(Sock,ce)!=1)
		{
			chat.receiveMessage(Sock,ce);
		}
			Sock.close();
		}
		
		
	}
	
	public int callServer() throws Exception
	{
		int port;
		port=5123;
		String ip;
		System.out.println("Give the ip of server:");
		Scanner ipinput = new Scanner(System.in);
		ip=ipinput.nextLine();
		Sock=new Socket(ip,port);
		PrintStream serverprint = new PrintStream(Sock.getOutputStream());
		BufferedReader serverread = new BufferedReader(new InputStreamReader(Sock.getInputStream()));
		
		ce=new ClientEnc();
		ce.init();
		
		serverprint.println("Hey! Want to chat? ;) My public key is :");
		serverprint.println(ce.modulus);
		serverprint.println(ce.publicExponent);
		
		Random rand = new Random();
		int R = rand.nextInt(5000) + 5000;
		BigInteger b,c;
		
		long startTime = System.currentTimeMillis();
		while ((System.currentTimeMillis() - startTime) < R && !serverread.ready()){
			
		}
		String r;
		if (serverread.ready()) {
			r = serverread.readLine();
		//	rtime = serverread.readLine();
		    System.out.println(r);
		    if(r.equals("Sure!"))
		    {
		    	 b = new BigInteger(serverread.readLine().getBytes());
		    	 System.out.println(b);
		    	 c = new BigInteger(serverread.readLine().getBytes());
		    	 System.out.println(c);
		    	 ce.setpub2(b,c);
				    return 1;
		    }
		    else{
		    	 Sock.close();
				    return 0;
		    }
		    
		} else {
		    System.out.println("You did not recieve response");
		    Sock.close();
		    return 0;
		}
		
	}
	
}
