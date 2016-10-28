package Problem_Number_11348;

import java.util.*;

public class Main {
	
	final static int sz=60;

	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		
		int testCase=sc.nextInt();
		
		int n,m,cs=1,i,j,v,tot,x,a;
		boolean fg;
		while(testCase-->0)
		{
			
			Map<Integer, Integer>mp=new HashMap<>();
			HashSet<Integer> s[]=new HashSet[sz];
			
			n=sc.nextInt();
			tot=0;
			
			for(i=1;i<=n;i++)
			{
				m=sc.nextInt();
				s[i]=new HashSet<>();
				
				for(j=0;j<m;j++)
				{
					a=sc.nextInt();
					if(mp.containsKey(a))
					{
						v=mp.get(a);
						if(v!=i)
						{
							if(s[v].contains(a))
							{
								s[v].remove(a);
							}
						}
					}
					else
					{
						mp.put(a, i);
						s[i].add(a);
					}
				}
			}
			
			for(i=1;i<=n;i++)
				tot+=s[i].size();
			
			System.out.print("Case " + cs++ + ":");
			for(i=1;i<=n;i++) 
			{
				if(tot>0)
					System.out.printf(" %6f%%", (double)(s[i].size()*100)/(double)tot);
			}
			
			System.out.println("");
		}	
	}
}
