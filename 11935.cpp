#include<stdio.h>
#include<string.h>
#define max(a,b) (a>b ?a:b)
#define eps 0.00000000001

char ch[100];
double pas,rat,n,sm,cnt,prev,now,mx;

int main()
{
	while(~scanf("%lf",&pas))
	{
		scanf("%s",ch);
		if(ch[0]=='F')
		{
			prev=pas;
			scanf("%s%lf",ch,&rat);
			if(rat==0&&pas==0)
				break;
		}
		sm=cnt=mx=0;
		while(scanf("%lf",&pas))
		{
			now=pas-prev;
			prev=pas;
			sm+=((now*rat)/100);
			sm+=(cnt*now);
			scanf("%s",ch);
			if(strcmp(ch,"Goal")==0)
				break;
			else if(ch[0]=='F')
				scanf("%s%lf",ch,&rat);
			else if(ch[0]=='L')
				cnt++;
			else if(ch[0]=='M')
				cnt=0;
			else
			{
				scanf("%s",ch);
				mx=max(sm,mx);
				sm=0;
			}
		}
		mx=max(mx,sm);
		printf("%.3lf\n",mx+eps);
	}
	return 0;
}