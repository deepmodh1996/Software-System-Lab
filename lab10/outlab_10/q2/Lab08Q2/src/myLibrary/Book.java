package myLibrary;

public class Book{
  static int content;
  static int nofr;
  static int wrt;
  static int req;
  
  public Book(){
      content=0;//version
      nofr=0;//no of readers currently
      wrt=0;//no of writers currently
      req=0;//no of requests from writers to write
  }
  int getcontent(){
    return content;
  }
  int getnofr(){
    return nofr;
  }
  public void read(Reader r){
   /*
      1.) will rest for 30 secs randomly --sleep
      2.) will see if its not reading same version (sleep for randon5 seconds if its the case) --while(true)
      3.) will see if writer is writing or is trying to write  --sync wait
      4.) will read for 5 secs  --sleep
      5.) do same steps again   --for loop
   */

   int old=-1;
   for(int y=0;y<2;y++){
    double ran=Math.random()*30;
    try{
      Thread.sleep((int)(ran*1000));
    }
    catch(InterruptedException e){
      System.out.println("interrupted");
    }

    while(old==content){
      try{
        ran=Math.random()*5;
        Thread.sleep((int)(ran*1000));
      }
      catch(InterruptedException e){
        System.out.println("interrupted");
      }
    }
    
    int temp,tmpcon;
    synchronized(this){//syncronized gate for reader to start reading book
      while(wrt==1||req>=7){
        try{
          this.notifyAll();
          wait();
        }
        catch(InterruptedException e){
          System.out.println("interrupted");
        }
      }
      nofr+=1;
      temp=nofr;
      tmpcon=content;
      System.out.println("Reader "+r.id+" is entering, Number of Readers: "+temp+" \n"+"Reader "+r.id +" is reading Book Version "+tmpcon);

      this.notifyAll();
    }
    
    //System.out.println("Reader "+r.id+" is entering, Number of Readers: "+temp+" \n"+"Reader "+r.id +" is reading Book Version "+tmpcon);
    try{
      Thread.sleep(5000);
    }
    catch(InterruptedException e){
      System.out.println("interrupted");
    }
    old=tmpcon;
    //nofr-=1;
    System.out.println("Reader "+r.id+" is leaving, Number of Readers: "+(nofr-1));
    nofr-=1;
   }

   synchronized(this){
    this.notifyAll();
   }

   return;

  }

  public void write(Writer w){
   /*
      1.) will wait to see if any reader is reading or not  --sync wait
      2.) write  --sleep
      3.) think for 2 sec --sleep
   */

   for(int k=0;k<5;k++){

     synchronized(this){
       try{
          while(nofr!=0){
            req+=1;
            this.notifyAll();
            wait();
          }
       }
       catch(InterruptedException e){
        System.out.println("interrupted");
       }
       wrt=1;
       System.out.println("Writer is entering");
       try{
        Thread.sleep(10000);
       }
       catch(InterruptedException e){
        System.out.println("interrupted");
       }
       content+=1;
       System.out.println("Writer is leaving");
       wrt=0; req=0;
       this.notifyAll();
     }

     try{
      Thread.sleep(2000);
     }
     catch(InterruptedException e){
      System.out.println("interrupted");
     }

   }

   return;

  }

}

