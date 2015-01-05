#include<stdio.h>
#include<math.h>
#define si 1000010

long pr[si],a[si],len=1,ind_l,ind_u,cnt[130];

void sieve()
{
	long i,j,n=si-10,root;
	pr[len++]=2;
	root=sqrt(n);
	for(i=3;i<=n;i=i+2)
	{
		if(a[i]==0)
		{
			pr[len++]=i;
			if(i<=root)
			{
				for(j=i*i;j<=n;j+=2*i)
					a[j]=1;
			}
		}
		a[i+1]=1;
    }
}

int main()
{
	long t,l,u,i,fg,beg,end,mid,mx,cnt_mx,dif,res;
	sieve();
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&l,&u);
		beg=1;
		end=len-1;
		fg=1;
		while(beg<=end)
		{
			mid=(beg+end)/2;
			if(pr[mid]==l)
			{
				fg=0;
				ind_l=mid;
				break;
			}
			else if(pr[mid]<l)
				beg=mid+1;
			else
				end=mid-1;
		}
		if(fg)
			ind_l=beg;

		beg=1;
		end=len-1;
		fg=1;
		while(beg<=end)
		{
			mid=(beg+end)/2;
			if(pr[mid]==u)
			{
				fg=0;
				ind_u=mid;
				break;
			}
			else if(pr[mid]<u)
				beg=mid+1;
			else
				end=mid-1;
		}
		if(fg)
			ind_u=end;
		mx=cnt_mx=0;
		for(i=ind_l;i<ind_u;i++)  
		{
			dif=pr[i+1]-pr[i];
			cnt[dif]++;
		}
		for(i=1;i<=120;i++)
		{
			if(cnt[i]>mx)
				mx=cnt[i],res=i,cnt_mx=1;
			else if(cnt[i]==mx)
				cnt_mx++;
			cnt[i]=0;
		}
		if(cnt_mx!=1)
			printf("No jumping champion\n");
		else
			printf("The jumping champion is %ld\n",res);
	}
	return 0;
}
