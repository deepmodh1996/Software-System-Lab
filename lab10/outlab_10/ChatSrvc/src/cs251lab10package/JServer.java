package cs251lab10package;

import java.io.*;
import java.math.BigInteger;
import java.net.*;
import java.text.SimpleDateFormat;
import java.util.*;

public class JServer {
    int i=0;
    Encryptor e;
	Socket Sock;
	ServerSocket SRVSOCK;
	 public static void main(String[] args) throws Exception
     {
         JServer SERVER = new JServer();
         SERVER.run();
     }
	 public void run() 
     {//System.out.println("aloha");
	try{	  SRVSOCK = new ServerSocket(5123);
	System.out.println("Waiting");
         Sock = SRVSOCK.accept();
         InputStreamReader IR = new InputStreamReader(Sock.getInputStream());
         BufferedReader BR = new BufferedReader(IR);
         
         PrintStream PS = new PrintStream(Sock.getOutputStream());
         String MESSAGE;
         BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
         
         e=new Encryptor();
         e.init();
         
         BigInteger b,c;
         Random rand = new Random();
 		int R = 10000;
         
         MESSAGE = BR.readLine();
         System.out.println(MESSAGE);
         b = new BigInteger(BR.readLine().getBytes());
         System.out.println(b);
         c = new BigInteger(BR.readLine().getBytes());
         System.out.println(c);
         
         e.setpub2(b,c);
         
         String sen,stime;
         //DataOutputStream dOut = new DataOutputStream(Sock.getOutputStream());

         System.out.println("Give Message to send to client:");
         long startTime = System.currentTimeMillis();
 		while ((System.currentTimeMillis() - startTime) < R && !in.ready()){
 			
 		}
 		if(!in.ready())
 		{
 			System.out.println("Client Disconnected");
 			run();
 		}
 		else{ PS.println(in.readLine());
         PS.println(e.modulus);
         PS.println(e.publicExponent);
 		}
         while(true){
      	   String endchat;
      	   endchat="ENDCHAT";
      	   MESSAGE = BR.readLine();
      	   sen=BR.readLine();
      	  System.out.println(sen+MESSAGE);
      	  if(MESSAGE.equals(endchat))
             { 
          	   System.out.println(MESSAGE);
          	   run();
          	   break;
             }
             System.out.println("Give Message to send to client:");
             sen=in.readLine();
             Date date = new Date();
             SimpleDateFormat sdf = new SimpleDateFormat("MM/dd/yyyy h:mm:ss a");
         	stime= sdf.format(date);
             PS.println(sen);
             PS.println(stime);
      	   
         }
	 
        
        }
	 catch(Exception e)
	 {
		 i=1;
	 }
		 
	try{
		SRVSOCK.close();
		Sock.close();
		if(i==1){i=0;run();}
		
		}
	catch(Exception e){}
	 
         
     }
	 
}
