#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;

char fnd[15][300],rep[15][300];
long n,i,l,j,k,x,fg,ll,a,in_fg,in;
string st,ch1;

int main()
{
	while(~scanf("%ld",&n)&&n)
	{
		getchar();
		for(i=0;i<n;i++)
		{
			gets(fnd[i]);
			gets(rep[i]);
		}
		getline(cin,ch1);
		l=ch1.length();
		for(i=0;i<n;i++)
		{
			while(1)
			{
				in=in_fg=0;
				for(j=0;j<l;j++)
				{
					k=fg=0;
					if(ch1[j]==fnd[i][k]&&in==0)
					{
						a=j;
						ll=strlen(fnd[i]);
						while(ch1[j]==fnd[i][k]&&j<l)
							j++,k++;
						
						if(ll==k)
						{
							in=fg=1;
							st+=rep[i];
							in_fg=1;
						}
						if(fg)
							j--;
						else
							j=a;
					}
					if(!fg)
						st+=ch1[j];
				}
				if(in_fg==0)
				{
					st.erase();
					break;
				}
				ch1=st;
				st.erase();
				l=ch1.length();
			}
		}
		cout<<ch1<<endl;
	}
	return 0;
}
