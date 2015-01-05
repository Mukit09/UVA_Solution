/*  //Less efficient code
#include<stdio.h>
#include<math.h>
#define min(a,b) (a<b ?a:b)
#define si 300

int ara[si],pr[si],ll=1,store1[10010],store2[10010],res1[10010],res2[10010];

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
	int i,n,j,t,m,l,k,cnt,a,ind1,ind2,fg,x=1,mn;
	sieve();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		l=sqrt(n)+1;
		ind1=ind2=1;
		cnt=0;
		for(i=2;i<=n;i++)
		{
			k=i;
			for(j=1;pr[j]<=l;j++)
			{
				if(k%pr[j]==0)
				{
					cnt=0;
					while(!(k%pr[j]))
					{
						k/=pr[j];
						cnt++;
					}
					if(!res1[pr[j]])
						store1[ind1++]=pr[j];
					res1[pr[j]]+=cnt;
				}
				if(k==1)
					break;
			}
			if(k>1)
			{
				if(!res1[k])
					store1[ind1++]=k;
				res1[k]++;
			}
		}
		l=sqrt(m)+1;
		k=m;
		ind2=1;
		cnt=0;
		for(i=1;pr[i]<=l;i++)
		{
			if(k%pr[i]==0)
			{
				cnt=0;
				while(!(k%pr[i]))
				{
					k/=pr[i];
					cnt++;
				}
				if(!res2[pr[i]])
					store2[ind2++]=pr[i];
				res2[pr[i]]+=cnt;
				
			}
			if(k==1)
				break;
		}
		if(k>1)
		{
			if(!res2[k])
					store2[ind2++]=k;
			res2[k]++;
		}
		k=m;
		fg=1;
		mn=999999;
		for(i=1;i<ind2;i++)
		{
			a=store2[i];
			if(res2[a]>res1[a])
				fg=0;
			else
				mn=min(mn,res1[a]/res2[a]);
			res2[a]=store2[i]=0;
		}
		for(i=1;i<ind1;i++)
		{
			res1[store1[i]]=0;
			store1[i]=0;
		}
		printf("Case %d:\n",x++);
		if(fg)
			printf("%d\n",mn);
		else
			printf("Impossible to divide\n");
	}
	return 0;
}
*/

// Efficient code which I coded after 10139
#include<stdio.h>
#include<math.h>
#define min(a,b) (a<b ?a:b)
#define si 300

int ara[si],pr[si],ll=1,store1[10010],res1[10010];

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
	int i,n,j,t,m,l,k,cnt,a,ind1,fg,x=1,mn;
	sieve();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		l=sqrt(m)+1;
		ind1=1;
		cnt=0;
		k=m;
		for(j=1;pr[j]<=l&&j<ll;j++)
		{
			if(k%pr[j]==0)
			{
				cnt=0;
				while(!(k%pr[j]))
				{
					k/=pr[j];
					cnt++;
				}
				store1[ind1++]=pr[j];
				res1[pr[j]]=cnt;
			}
			if(k==1)
				break;
		}
		if(k>1)
		{
			store1[ind1++]=k;
			res1[k]=1;
		}
		fg=1;
		mn=999999;
		for(i=1;i<ind1;i++)
		{
			a=store1[i];
			k=1;
			cnt=0;
			while(1)
			{
				m=pow(a,k);
				j=n/m;
				if(j==0)
					break;
				cnt+=j;
				k++;
			}
			if(cnt<res1[a])
				fg=0;
			mn=min(mn,cnt/res1[a]);
		}
		printf("Case %d:\n",x++);
		if(fg)

			printf("%d\n",mn);
		else
			printf("Impossible to divide\n");
	}
	return 0;
}
