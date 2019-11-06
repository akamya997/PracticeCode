import java.math.BigInteger;
import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner cin=new Scanner(System.in);
		int T=cin.nextInt();
		while(cin.hasNext())
		{
			int n=cin.nextInt();
			BigInteger two = new BigInteger ("2");
			System.out.println(two.pow(n).toString());
		}
	}
}
