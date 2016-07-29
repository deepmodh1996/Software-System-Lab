/* put this file in the foo directory. go outside the foo directory
 * one level up, and run the program as java foo.NthRootExample */


import java.io.*;
import java.util.*;
import java.math.*;

/**
 *
 * @author HP
 */
public class NthRoot {

    /* simple non-optimized factorial */
    static BigDecimal fact(BigDecimal num,int n){
        BigDecimal x=new BigDecimal("1.000000");
        BigDecimal y=new BigDecimal("1.000000");
        BigDecimal one=new BigDecimal("1.000000");
        BigDecimal d=new BigDecimal("1000000.000000");
        BigDecimal z=new BigDecimal("1.000000");
        BigDecimal k=new BigDecimal(n);

      //  x=x.setScale(6);
    //    y=y.setScale(6);
  //      one=one.setScale(6);
//        d=d.setScale(6);
//        z=z.setScale(6);
//        k=k.setScale(6);
        //x=x.setScale(6);

        z=z.divide(d);

        x=num;
        y=(((k.subtract(one)).multiply(x)).add(num.divide(x.pow(n-1), 6, RoundingMode.HALF_UP))).divide(k, 6, RoundingMode.HALF_UP);
        //System.out.println(y);
        d=y.subtract(x);
        while(d.abs().compareTo(z)==1)
        {//System.out.println(y);
            x=y;
            y=(((k.subtract(one)).multiply(x)).add(num.divide(x.pow(n-1), 6, RoundingMode.HALF_UP))).divide(k, 6, RoundingMode.HALF_UP);
            d=y.subtract(x);
        }
        return y;
    }


    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println("Give num and n to find nth root of num");
        Scanner scanin=new Scanner(System.in);
        double d=scanin.nextDouble();
        BigDecimal num=new BigDecimal(d);
     //   scanin.close();
        int n=scanin.nextInt();
      System.out.println("answer: "+fact(num,n));
    }
}
