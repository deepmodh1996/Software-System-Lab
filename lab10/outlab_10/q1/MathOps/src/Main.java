import mathOps.gcd;
import mathOps.lcm;

public class Main {
	public static void main(String[] args) {
        System.out.println("Hello World!"); // Display the string.
        int a = 30;
        int b = 112;
        gcd gcd_obj = new gcd();
        lcm lcm_obj = new lcm();
        System.out.println("GCD of numbers is "+ gcd_obj.calculateGcd(a, b));
        System.out.println("Recursive GCD of numbers is "+ gcd_obj.myGcd(a, b));
        System.out.println("LCM of numbers is "+ lcm_obj.calculateLcm(a, b));
    }
}
