package mathOps;

public class lcm {
	public int calculateLcm(int a, int b){
		gcd obj = new gcd();
		return a*b/obj.calculateGcd(a, b);
	}
}
