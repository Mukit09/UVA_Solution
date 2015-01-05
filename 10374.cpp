#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>

using namespace std;

map<string,long>mp;
map<string,string>mpn;

char ch[30][90];
char pt[90];

int main()
{
	long i,t,max,cntmx,n,m;
	scanf("%ld",&t);

	while(t--)
	{
		scanf("%ld",&n);
		getchar();
		i=1;
		while(n--)
		{
			gets(ch[i]);
			gets(pt);
			mpn[ch[i]]=pt;
			i++;
		}
		n=i;
		scanf("%ld",&m);
		getchar();
		while(m--)
		{
			gets(pt);
			mp[pt]++;
		}
		cntmx=max=0;
	
		for(i=1;i<n;i++)
		{
			if(mp[ch[i]]>max)
			{
				max=mp[ch[i]];
				cntmx=1;
				m=i;
			}
			else if(max==mp[ch[i]])
				cntmx++;
		}
		if(cntmx>1)
			printf("tie\n");
		else
			cout<<mpn[ch[m]]<<endl;
			
		if(t)
			printf("\n");
		mp.clear();
		mpn.clear();
	}
	return 0;
}





/*
#include<stdio.h>
#include<string.h>

int main()
{
	char sa[22][82],si[22][82],temp[82];
	long a1,i,j,k,sn[22],a,n,m,max,max1;
	scanf("%ld",&a);
	for(a1=0;a1<a;a1++)
	{
		if(a1!=0)	
			printf("\n");
		scanf("%ld",&n);
		gets(sa[0]);
		for(i=0;i<n;i++)
		{
			gets(sa[i]);
			gets(si[i]);
			sn[i]=0;
		}
		scanf("%ld",&m);
		gets(temp);
		for(i=0;i<m;i++)
		{
			gets(temp);
			for(j=0;j<n;j++)
			{
				k=strcmp(temp,sa[j]);
				if(k==0)
				{
					sn[j]++;
					break;
				}
			}
		}
		max=0;
		max1=0;
		k=0;
		for(i=0;i<n;i++)
		{
			if(sn[i]>max)
			{
				 max=sn[i];
				 max1=1;
				 k=i;
			}
			else if(sn[i]==max)
			{
				max1++;
			}
		}
		if(max1>1)
			printf("tie\n");
		else
			printf("%s\n",si[k]);
	}
}*/