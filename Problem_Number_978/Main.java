package Problem_Number_978;

import java.util.*;

public class Main {
	
	static final int sz=100010;

	public static void main(String[] args) {

		Scanner sc=new Scanner(System.in);
		
		int[] tmp1=new int[sz];
		int[] tmp2=new int[sz];
		
		int testCase=sc.nextInt();
		int i,j,n,b,sg,sb,p,q,l,cnt;
		boolean gFg,bFg;
		
		while(testCase-->0)
		{
			TreeSet<Integer> tSetg=new TreeSet<>(); 
			TreeSet<Integer> tSetb=new TreeSet<>();
			Map<Integer,Integer> mpG=new HashMap<>();
			Map<Integer,Integer> mpB=new HashMap<>();
			
			gFg=bFg=false;
			
			b=sc.nextInt();
			sg=sc.nextInt();
			sb=sc.nextInt();
			
			for(i=0;i<sg;i++)
			{
				n=sc.nextInt();
				tSetg.add(n);
				if(mpG.containsKey(n))
					mpG.put(n, mpG.get(n)+1);
				else
					mpG.put(n, 1);
			}
			
			for(i=0;i<sb;i++)
			{
				n=sc.nextInt();
				tSetb.add(n);
				if(mpB.containsKey(n))
					mpB.put(n, mpB.get(n)+1);
				else
					mpB.put(n, 1);
			}
			
			while(true)
			{
				if(tSetg.isEmpty())
					gFg=true;
				if(tSetb.isEmpty())
					bFg=true;
				if(gFg || bFg)
					break;
				
				i=0;
				while(i<b)
				{
					if(tSetg.isEmpty() || tSetb.isEmpty())
						break;
					
					tmp1[i]=tSetg.last();
					tmp2[i]=tSetb.last();
					
					if(mpG.containsKey(tmp1[i]))
					{
						cnt=mpG.get(tmp1[i]);
						if(cnt==1)
						{
							tSetg.remove(tmp1[i]);
							mpG.remove(tmp1[i]);
						}
						else
							mpG.put(tmp1[i], mpG.get(tmp1[i])-1);
					}
					
					if(mpB.containsKey(tmp2[i]))
					{
						cnt=mpB.get(tmp2[i]);
						if(cnt==1)
						{
							tSetb.remove(tmp2[i]);
							mpB.remove(tmp2[i]);
						}
						else
							mpB.put(tmp2[i], mpB.get(tmp2[i])-1);
					}
					
					i++;
				}
				
				for(j=0;j<i;j++)
				{
					p=tmp1[j];
					q=tmp2[j];
					
					if(p>q)
					{
						tSetg.add(p-q);
						if(mpG.containsKey(p-q))
							mpG.put(p-q, mpG.get(p-q)+1);
						else
							mpG.put(p-q, 1);
					}
					else if(q>p)
					{
						tSetb.add(q-p);
						if(mpB.containsKey(q-p))
							mpB.put(q-p, mpB.get(q-p)+1);
						else
							mpB.put(q-p, 1);
					}
				}
			}
			if(gFg && bFg)
				System.out.println("green and blue died");
			else if(gFg)
			{
				System.out.println("blue wins");
				l=tSetb.size();
				for(i=0;i<l;i++)
				{
					n=tSetb.last();
					cnt=mpB.get(n);
					while(cnt-->0)
						System.out.println(n);
					tSetb.remove(n);
				}
			}
			else 
			{
				System.out.println("green wins");
				l=tSetg.size();
				for(i=0;i<l;i++)
				{
					n=tSetg.last();
					cnt=mpG.get(n);
					while(cnt-->0)
						System.out.println(n);
					tSetg.remove(n);
				}
			}
			if(testCase>0)
				System.out.println("");
		}
	}
}
