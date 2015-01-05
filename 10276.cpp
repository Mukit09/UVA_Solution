#include<stdio.h>
#include<math.h>

int a[60],n,chk[60],mx;

void rec(int now,int mx_p)
{
	int i,total,root;
	for(i=1;i<=mx_p;i++)
	{
		if(chk[i]==1)
		{
			total=now+a[i];
			root=sqrt(total);
			if(root*root==total)
			{
				a[i]=now;
				mx=now;
				rec(now+1,mx_p);
				return ;
			}
		}
	}	
	if(mx_p+1<=n)
	{
		mx=a[i]=now;
		chk[i]=1;
		rec(now+1,mx_p+1);
	}
}

int main()
{
	int i,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		mx=a[1]=chk[1]=1;
		rec(2,1);
		printf("%d\n",mx);
	}
	return 0;
}