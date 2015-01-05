#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define si 1010
char ch[10];

int ara[si],pr[si],ll=1,pw;

void sieve()
{
	int num=si-5,i,j,root;
	root=sqrt(num);
	ara[0]=ara[1]=1;
	pr[ll++]=2;
	for(i=3;i<=num;i=i+2)
	{
		if(ara[i]==0)
		{
			pr[ll++]=i;
			if(i<=root)
			{
				for(j=i*i;j<=num;j+=2*i)
					ara[j]=1;
			}
		}
		ara[i+1]=1;
    }
}

int cnt_pw(int m)
{
	int cnt=0;
	while(m)
	{
		m/=10;
		cnt++;
	}
	return cnt;
}

int chk(int x)
{
	int i;
	while(x)
	{
		i=x%10;
		if(i%2==0||i==5)
			return 0;
		x/=10;
	}
	return 1;
}

int chk_res(int x)
{
	int l,i,sm;
	l=sprintf(ch,"%d",x);
	sort(ch,ch+l);
	do
	{
		sm=0;
		for(i=0;i<l;i++)
			sm=sm*10+(ch[i]-48);
		if(ara[sm])
			return 0;
	}while(next_permutation(ch,ch+l));
	return 1;
}

int main()
{
	int i,n,ck,fg;
	sieve();
	while(~scanf("%d",&n)&&n)
	{
		if(n>=1000)
		{
			printf("0\n");
			continue;
		}
		if(n==1)
		{
			printf("2\n");
			continue;
		}
		pw=cnt_pw(n);
		pw=pow(10,pw);
		if(n%2==0)
			n++;
		else
			n+=2;
		fg=0;
		for(i=n;i<=pw;i+=2)
		{
			ck=chk(i);
			if(!ck&&i>10)
				continue;
			ck=0;
			if(ara[i]==0)
				ck=chk_res(i);
			if(ck)
			{
				fg=1;
				break;
			}
		}
		if(fg)
			printf("%d\n",i);
		else
			printf("0\n");
	}
	return 0;
}