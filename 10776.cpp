#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
vector<char>ve;
map<string,long>mp;

long l,take[40],r,a[150];
char ch[40],re[40];
string st;

void rec(long j)
{
	long i;
	if(ve.size()==r)
	{
		for(i=0;i<r;i++)
		{
			re[i]=ve[i];
			if(i==0)
				a[ve[i]]=1;
		}
		re[i]=0;
		st=re;
		if(mp[st]==0)
		{
			mp[st]=1;
			printf("%s\n",re);
		}
	}
	else
	{
		for(i=j;i<l;i++)
		{
			if(take[i]==0&&a[ch[i]]==0)
			{
				take[i]=1;
				ve.push_back(ch[i]);
				rec(i+1);
				ve.pop_back();
				take[i]=0;
			}
		}
	}
}

int main()
{
	long i;
	while(~scanf("%s%ld",ch,&r))
	{
		l=strlen(ch);
		sort(ch,ch+l);
		for(i=97;i<=122;i++)
			a[i]=0;
		rec(0);
		mp.clear();
	}
	return 0;
}