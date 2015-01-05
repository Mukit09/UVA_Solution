#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
	long double hum[5900],a,n,arr[]={2,3,5,7};
	long i,j,k;
	bool fg;
	stack<long double>stk;
	j=1;
	hum[0]=1;
	for(i=0;i<4;i++)
	{
		a=arr[i];
		hum[j++]=a;
		stk.push(a);
	}
	while(!stk.empty())
	{
		n=stk.top();
		stk.pop();
		for(i=0;i<4;i++)
		{
			a=n*arr[i];
			if(a<2000000000)
			{
				fg=0;
				for(k=j-1;k>=0;k--)
				{
					if(a==hum[k])
					{
						fg=1;
						break;
					}
				}
				if(!fg)
				{
					hum[j++]=a;
					stk.push(a);
				}
			}
		}
	}
	hum[j++]=2000000000;
	sort(hum,hum+j);
	while(scanf("%ld",&i) && i)
	{
		if(i%10==1 && i%100!=11)
			printf("The %ldst humble number is %.0llf.\n",i,hum[i-1]);
		else if(i%10==2 && i%100!=12)
			printf("The %ldnd humble number is %.0llf.\n",i,hum[i-1]);
		else if(i%10==3 && i%100!=13)
			printf("The %ldrd humble number is %.0llf.\n",i,hum[i-1]);
		else
			printf("The %ldth humble number is %.0llf.\n",i,hum[i-1]);
	}
	return 0;
}
