#include<stdio.h>
#include<algorithm>

using namespace std;
  
long cnt,w[30],m,x[30],fg;
  
void subset(long s,long k,long r)
{
	x[k]=1;
	if(s+w[k]==m)
		fg=1;
	else if(s+w[k]+w[k+1] <=m)
		subset(s+w[k],k+1,r-w[k]);
    if((s+r-w[k]>=m)&&(s+w[k+1])<=m)
    {               
		x[k]=0;
		subset(s,k+1,r-w[k]);
    }
}
  
int main()
{
    long sum=0,i,n,t;
	scanf("%ld",&t);
    while(t--)
	{
		scanf("%ld",&m);
		scanf("%ld",&n);
		for(i=0; i<n; i++)
			scanf("%d",&w[i]);
		sort(w,w+n);
		sum=fg=0;
		for(i=0; i<n; i++)
			sum +=w[i]; 
		subset(0,0,sum);
		if(fg||m==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
    return 0;
   
}
