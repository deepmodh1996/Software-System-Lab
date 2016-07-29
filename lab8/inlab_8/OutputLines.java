import java.io.*;

public class OutputLines{
  public static void main(String args[]){
    String line="";
    try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
      line = br.readLine();
    }
    catch(IOException io){
      System.out.println("Could not take input. Sorry.");
    }
    
    try (BufferedReader br1 = new BufferedReader(new FileReader(line))) {
       String str;
       int i=1;
       while ((str = br1.readLine()) != null) {
          System.out.println(i+": "+str);
          i++;
       }
    }
    catch(IOException io){
      System.out.println("Could not read the file. Sorry.");
    }
        
  } 
}
