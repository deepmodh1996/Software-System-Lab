package mathOps;

public class gcd {
	public int calculateGcd(int a, int b){
		    return b == 0 ? a : calculateGcd(b, a % b);
	}
	public int myGcd(int m, int n) {
		int r = m % (n);
		  if (r != 0)  {
		    return myGcd (n, r);
		  }
		  else return n;
	}
}
