package Problem_Number_11136;

import java.util.*;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		
		long n,billNumber,bill,sum,p,q,cnt;
		while((n=sc.nextInt())>0)
		{
			TreeSet<Long> s=new TreeSet<>();
			Map<Long, Long> mp=new HashMap<>();
			sum=0;
			while(n-->0)
			{
				billNumber=sc.nextInt();
				while(billNumber-->0)
				{
					bill=sc.nextInt();
					if(mp.containsKey(bill))
						cnt=mp.get(bill);
					else
						cnt=0;
					mp.put(bill, cnt+1);
					s.add(bill);
				}
				p=s.first();
				if(mp.get(p)==1)
				{
					mp.remove(p);
					s.remove(p);
				}
				else
					mp.put(p, mp.get(p)-1);
				q=s.last();
				if(mp.get(q)==1)
				{
					mp.remove(q);
					s.remove(q);
				}
				else
					mp.put(q, mp.get(q)-1);
				sum+=(q-p);
			}
			System.out.println(sum);
		}
	}
}
