import java.math.BigInteger;

public class FactorialDivisor{
  public static void main(String args[]){
        BigInteger a=BigInteger.valueOf(1);
        BigInteger bj=a;
        BigInteger bi=a;
        BigInteger f=a;
        BigInteger g=a;
        BigInteger one=BigInteger.valueOf(1);
        BigInteger zero=BigInteger.valueOf(0);
        int i=0,j=1,exp=1234,sum=0;
        for(i=2;i<=10;i++)
        {
          bi=bi.add(one);
          f=f.multiply(bi.pow(exp));
          for(;j<12340;j++)
          {            
            if((g.remainder(f).compareTo(zero))==0)
            {
              break;
            }
            g=g.multiply(bj);
            bj=bj.add(one);
          //System.out.println(bj+"lol");  
          }
          //System.out.println(j-1);
          sum=sum+j-1;
        }
         System.out.println(sum);
  } 
}