#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
#include<string>
#include<algorithm>

using namespace std;
long i,k,l,t,n,j,a,fg;

map<string,long>mp;

struct ss
{
	string st;
}T[100005];

bool cmp(ss aa,ss bb)
{
	if(aa.st>bb.st)
		return false;
	else return true;
}

int main()
{
	char in[100005],ch[100005];
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		fg=a=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",in);
			l=strlen(in);
			k=0;
			for(j=0;j<l;j++)
			{
				if(in[j]=='-')
					continue;
				else
				{
					if(in[j]=='A'||in[j]=='B'||in[j]=='C')
						ch[k]='2';
					else if(in[j]=='D'||in[j]=='E'||in[j]=='F')
						ch[k]='3';
					else if(in[j]=='G'||in[j]=='H'||in[j]=='I')
						ch[k]='4';
					else if(in[j]=='J'||in[j]=='K'||in[j]=='L')
						ch[k]='5';
					else if(in[j]=='M'||in[j]=='N'||in[j]=='O')
						ch[k]='6';
					else if(in[j]=='P'||in[j]=='R'||in[j]=='S')
						ch[k]='7';
					else if(in[j]=='T'||in[j]=='U'||in[j]=='V')
						ch[k]='8';
					else if(in[j]=='W'||in[j]=='X'||in[j]=='Y')
						ch[k]='9';
					else
						ch[k]=in[j];
				}
				k++;
				if(k==3)
					ch[k++]='-';
			}
			ch[k]=0;
			if(mp[ch]==0)
			{
				T[a].st=ch;
				a++;
			}
			mp[ch]++;
			if(mp[ch]>1)
				fg=1;
		}

		if(!fg)
		{
			printf("No duplicates.\n");
			if(t)
				printf("\n");
			mp.clear();
			continue;
		}
		sort(T,T+a,cmp);
		for(i=0;i<a;i++)
		{
			if(mp[T[i].st]>1)
			{
				cout<<T[i].st;
				printf(" %ld\n",mp[T[i].st]);
			}
		}
		if(t)
			printf("\n");
		mp.clear();
	}
	return 0;
}
