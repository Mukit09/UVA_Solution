#include<stdio.h>
#include<string.h>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

map<string,long>mp;

char ch[15];
long i,t,n,fg,j,l;

struct ss
{
	string st;
	long len;
}T[10010];

bool cmp(ss aa,ss bb)
{
	if(aa.len<bb.len) return true;
	else if(aa.len==bb.len)
	{
		if(aa.st<bb.st) return true;
		else return false;
	}
	return false;
}

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		i=0;
		while(n--)
		{
			scanf("%s",ch);
			l=strlen(ch);
			T[i].st=ch;
			T[i].len=l;
			i++;
		}
		sort(T,T+i,cmp);
		n=i;
		fg=0;
		for(i=0;i<n;i++)
		{
			if(mp[T[i].st]==0)
			{
				j=0;
				while(T[i].st[j])
				{
					ch[j]=T[i].st[j];
					j++;
					ch[j]=0;
					if(mp[ch]==1)
					{
						fg=1;
						break;
					}
				}
				if(fg)
					break;
				mp[T[i].st]=1;
			}
			else
			{
				fg=1;
				break;
			}
		}
			
		if(fg)
			printf("NO\n");
		else
			printf("YES\n");
		mp.clear();
	}
	return 0;
}