#include<stdio.h>
#include<math.h>
#include<map>
using namespace std;
#define si 50020
map<int,int>mp;
int ara[si],pr[si],ll=1,store[si];

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
    }
}

int main()
{
	int i,n,j,l,m,a,b,fg,x,cnt,k;
	sieve();
	while(~scanf("%d%d",&n,&a))
	{
		if(n>=a&&a)
		{
			printf("%d divides %d!\n",a,n);
			continue;
		}
		else if(!a)
		{
			printf("%d does not divide %d!\n",a,n);
			continue;
		}
		j=1;
		l=sqrt(a)+1;
		x=a;
		for(i=1;pr[i]<=l&&i<ll;i++)
		{
			if(x%pr[i]==0)
			{
				cnt=0;
				while(x%pr[i]==0)
				{
					x/=pr[i];
					cnt++;
				}
				store[j++]=pr[i];
				mp[pr[i]]=cnt;
			}
			if(x==1)
				break;
		}
		if(x>1)
		{
			store[j++]=x;
			mp[x]=1;
		}
		fg=1;
		for(i=1;i<j;i++)
		{
			k=1;
			cnt=0;
			while(1)
			{
				x=pow(store[i],k);
				m=n/x;
				if(m==0)
					break;
				cnt+=m;
				if(cnt>=mp[store[i]])
					break;
				k++;
			}
			if(cnt<mp[store[i]])
			{
				fg=0;
				break;
			}
		}
		if(fg)
			printf("%d divides %d!\n",a,n);
		else
			printf("%d does not divide %d!\n",a,n);
	}
	return 0;
}
