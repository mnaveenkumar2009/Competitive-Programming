import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;
 
/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{   
    static BigInteger f2(int N,BigInteger lll)
    {       
        BigInteger b2 = new BigInteger("2");
              BigInteger bi[] = lll.divideAndRemainder(b2);
 
        if(N==0)
        {
        return (lll);
        }
       BigInteger rew= new BigInteger("2").pow(N-1);
       BigInteger www =  new BigInteger("0");
        if(bi[1].compareTo(www)==0)
        {
         return f2(N-1,bi[0]);   
        }
        else
        {
            return ((rew).add(f2(N-1,bi[0])));
        }
        
    }
    
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
	    for(int yy=0;yy<t;yy++)
	    {
            int N = sc.nextInt();
            BigInteger lll = sc.nextBigInteger();
            System.out.println(f2(N,lll));
	    }
	}
} 