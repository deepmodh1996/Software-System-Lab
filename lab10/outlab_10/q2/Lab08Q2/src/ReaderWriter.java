import myLibrary.Book;
import myLibrary.Reader;
import myLibrary.Writer;


public class ReaderWriter {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Book b=new Book();
        Writer w=new Writer(b);
        w.start();
        Reader[] readers=new Reader[20];
        for(int i=0;i<20;i++){
            readers[i]=new Reader(b);
            readers[i].setid(i+1);
            //Running thread one after another
        }
        for(int i=0;i<20;i++){
        	readers[i].start();
        }
	}

}
