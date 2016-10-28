package Problem_Number_10132;

import java.util.*;

public class Main {
 
	public static void main(String[] args) {
 
		Scanner sc=new Scanner(System.in);
 
		String st[]=new String[300];
		String tmpStr[]=new String[300];
		String ans, made;
 
		int testCase=sc.nextInt();
		sc.nextLine();
		sc.nextLine();
 
		int i=0,l,j,n,x,y,cnt,fg;
		while(testCase-->0)
		{
			n=0;
			while(sc.hasNext())
			{
				st[n]=sc.nextLine();
				if(st[n].equals(""))
					break;
				tmpStr[n]=st[n];
				n++;
			}
			fg=0;
			ans=null;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(i!=j)
					{
						String tmp=st[i]+st[j];
						cnt=0;
 
						for(x=0;x<n;x++)
						{
							for(y=x+1;y<n;y++)
							{
								if(tmp.equals(tmpStr[x]+tmpStr[y])||tmp.equals(tmpStr[y]+tmpStr[x]))
								{
									tmpStr[x]="*";
									tmpStr[y]="*";
									cnt++;
 
									if(cnt==n/2)
									{
										ans=tmp;
										fg=1;
									}
								}
								if(fg==1)
									break;
							}
							if(fg==1)
								break;
						}
						for(x=0;x<n;x++)
							tmpStr[x]=st[x];
 
					}
					if(fg==1)
						break;
				}
				if(fg==1)
					break;
			}
			System.out.println(ans);
 
			if(testCase>0)
				System.out.println("");
		}
	}
}