package Problem_Number_11572;

import java.util.*;

public class Main {

	public static void main(String[] args) {
	
		Scanner sc=new Scanner(System.in);
		int testCase=sc.nextInt();
		int n,i,v,mx,j,start;
		while(testCase-->0)
		{
			mx=start=0;
			j=0;
			Map<Integer, Integer> mp=new HashMap<>();
			
			n=sc.nextInt();
			
			for(i=0;i<n;i++)
			{
				v=sc.nextInt();
				if(mp.containsKey(v))
				{
					j=mp.get(v);
					start=Math.max(j+1, start);
				}
				mx=Math.max(mx, i-start+1);
				mp.put(v, i);
			}
			
			System.out.println(mx);
			mp.clear();
		}
	}
}
