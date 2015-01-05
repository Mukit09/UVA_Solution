#include<stdio.h>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

map<string,long>mp;

struct ss
{
	long cst,man_mark;
}T[25];

bool cmp(ss aa,ss bb)
{
	return aa.cst<bb.cst;
}

int main()
{
	char ch[35][500],st1[500],st2[500];
	long cst,i,n,p,t,j,q,x=1;
	while(~scanf("%ld%ld",&n,&t)&&(n||t))
	{
		p=0;
		for(i=0;i<n;i++)
		{
			T[i].cst=0;
			scanf("%s",ch[i]);
			mp[ch[p]]=p;
			T[i].man_mark=i;
			p++;
		}
		for(i=1;i<=t;i++)
		{
			scanf("%s%s%ld",st1,st2,&cst);
			p=mp[st1];
			q=mp[st2];
			T[p].cst-=cst;
			T[q].cst+=cst;
		}
		sort(T,T+n,cmp);
		i=0;
		while(T[i].cst<0)
			i++;
		q=i;
		printf("Case #%ld\n",x++);
		for(i=0,j=q;i<n;)
		{
			if(T[i].cst+T[j].cst<=0&&T[j].cst!=0)
			{
				T[i].cst+=T[j].cst;
				printf("%s %s %ld\n",ch[T[j].man_mark],ch[T[i].man_mark],T[j].cst);
				j++;
			}
			else if(T[i].cst+T[j].cst>0&&T[i].cst!=0)
			{
				T[j].cst+=T[i].cst;
				printf("%s %s %ld\n",ch[T[j].man_mark],ch[T[i].man_mark],-T[i].cst);	
				i++;
			}
			if(T[i].cst==0)
				i++;
			if(T[j].cst==0)
				j++;
			if(T[i].cst>0||T[j].cst<0)
				break;
		}
		printf("\n");
	}
	return 0;
}