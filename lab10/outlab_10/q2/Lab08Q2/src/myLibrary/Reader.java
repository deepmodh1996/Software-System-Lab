package myLibrary;

public class Reader extends Thread{
	   static Book b;
	   static int num;
	   int flag;
	   int id;
	   public Reader(Book b1){
	   	b=b1;
	   	num=0;
	   	id=-1;
	    flag=-1;
	   }
	   public void setid(int i){
	   	id=i;
	   }
	   public void run(){
	      b.read(this);
	   }

	}