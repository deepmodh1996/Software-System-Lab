/* put this file in the foo directory. go outside the foo directory
 * one level up, and run the program as java foo.NthRootExample */

import java.math.BigDecimal;

/**
 *
 * @author HP
 */
public class SolveBigEquation {
       public static void main(String[] args){
        BigDecimal FIFTY=new BigDecimal("50.000000");
        BigDecimal HUN=new BigDecimal("100.000000");
        BigDecimal one=new BigDecimal("1.000000");
        BigDecimal bj=new BigDecimal("1.000000");
        BigDecimal f=new BigDecimal("1.000000");
           int i=1;
           for(i=1;i<=50;i++)
           {
            f=f.multiply(bj);
            bj=bj.add(one);
           }
           FIFTY=f;
           for(i=1;i<=50;i++)
           {
            f=f.multiply(bj);
            bj=bj.add(one);
           }
           HUN=f;
           BigDecimal D=new BigDecimal("1.000000");
           BigDecimal b=new BigDecimal("1.000000");
           BigDecimal a=new BigDecimal("2.000000");
           BigDecimal cons=new BigDecimal("4.000000");
           D=(FIFTY.multiply(FIFTY)).add(HUN.multiply(cons));

           BigDecimal y=new BigDecimal("1.000000");
           BigDecimal x=new BigDecimal("1.000000");
           BigDecimal m=new BigDecimal("1.000000");
           BigDecimal z=new BigDecimal("1.000000");
           BigDecimal d=new BigDecimal("1000000.000000");
           BigDecimal ac=new BigDecimal("1.000000");
           BigDecimal ans=new BigDecimal("1.000000");
           BigDecimal ans1=new BigDecimal("1.000000");

           y=D;
           ac=D;
           z=z.divide(d);
           b=FIFTY;

          // System.out.println(z);



            while((y.subtract(x)).compareTo(z)==1)
        {m=(x.add(y)).divide(a);
            if((m.multiply(m)).compareTo(ac)!=1)
            {
                x=m;
            }
            else{y=m;}
        }
        //System.out.println(ans);
        D=y;
        ans=(b.add(D)).divide(a);
        ans1=ans.subtract(b);
        System.out.println(ans.setScale(3,BigDecimal.ROUND_UP)+","+ans1.setScale(3,BigDecimal.ROUND_UP));
        System.out.println(ans1.setScale(3,BigDecimal.ROUND_UP)+","+ans.setScale(3,BigDecimal.ROUND_UP));
        ans=(b.subtract(D)).divide(a);
        ans1=ans.subtract(b);
        System.out.println(ans.setScale(3,BigDecimal.ROUND_UP)+","+ans1.setScale(3,BigDecimal.ROUND_UP));
        System.out.println(ans1.setScale(3,BigDecimal.ROUND_UP)+","+ans.setScale(3,BigDecimal.ROUND_UP));
    }

}
