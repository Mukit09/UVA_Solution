#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
vector<char>ve;

char ch[1100],st[1100],c;
long take[30],chk[30][30],l,found;

void reset()
{
	long i,j;
	for(i=0;i<26;i++)
	{
		for(j=0;j<26;j++)
			chk[i][j]=1;
	}
}

long check(long len,long c)
{
	long i;
	for(i=0;i<len;i++)
	{
		if(chk[ve[i]-'A'][c]==0)
			return 0;
	}
	return 1;
}

void rec(long len)
{
	long i;
	if(len==l)
	{
		printf("%c",ve[0]);
		for(i=1;i<l;i++)
			printf(" %c",ve[i]);
		printf("\n");
		found=1;
	}
	else
	{
		for(i=0;i<l;i++)
		{
			if(take[i]==0&&check(len,ch[i]-'A')==1)
			{
				take[i]=1;
				ve.push_back(ch[i]);
				rec(len+1);
				ve.pop_back();
				take[i]=0;
			}
		}
	}
}


int main()
{
	long i,fg,t;
	scanf("%ld",&t);
	getchar();
	while(t--)
	{
		getchar();
		gets(st);
		l=0;
		for(i=0;st[i];i++)
		{
			if(st[i]>=65&&st[i]<=90)
				ch[l++]=st[i];
		}
		gets(st);
		reset();
		fg=1;
		for(i=0;st[i];i++)
		{
			if(st[i]>=65&&st[i]<=90)
			{
				if(fg)
				{
					c=st[i];
					fg=0;
				}
				else
				{
					chk[st[i]-'A'][c-'A']=0;
					fg=1;
				}
			}
		}
		sort(ch,ch+l);
		found=0;
		rec(0);
		if(!found)
			printf("NO\n");
		if(t)
			printf("\n");
	}
	return 0;
}