#include<stdio.h>
#include<algorithm>
using namespace std;

struct ss
{
	long h1,m1,h2,m2;
}T[110];

bool cmp(ss aa,ss bb)
{
	if(aa.h1>bb.h1)
		return false;
	else if(aa.h1==bb.h1)
	{
		if(aa.m1>bb.m1)
			return false;
	}
	return true;
}

int main()
{
	long i,k=1,u,top,mx,h,m,n,dh,dm,fg;
	char c;
	while(~scanf("%ld",&n))
	{
		fg=1;
		mx=0;
		for(i=0;i<n;i++)
		{
			scanf("%ld%c%ld%ld%c%ld",&T[i].h1,&c,&T[i].m1,&T[i].h2,&c,&T[i].m2);
			c=getchar();
			while(c!='\n')
				c=getchar();
		}
		sort(T,T+n,cmp);
		for(i=0;i<n;i++)
		{
			if(fg)
			{
				fg=0;
				top=(T[i].h1*60+T[i].m1)-600;
				u=T[i].h2*60+T[i].m2;
				if(top>mx)
				{
					mx=top;
					h=10;
					m=0;
				}
				continue;
			}
			top=(T[i].h1*60+T[i].m1)-u;
			if(top>mx)
			{
				mx=top;
				h=u/60;
				m=u%60;
			}
			u=T[i].h2*60+T[i].m2;
		}
		if(1080-u>mx)
		{
			mx=1080-u;
			h=u/60;
			m=u%60;
		}
		dh=mx/60;
		dm=mx%60;
		if(n==0)
		{
			dh=8;
			dm=0;
			h=10;
			m=0;
		}


		if(dh!=0)
			printf("Day #%ld: the longest nap starts at %02ld:%02ld and will last for %ld hours and %ld minutes.\n",k++,h,m,dh,dm);
		else
			printf("Day #%ld: the longest nap starts at %02ld:%02ld and will last for %ld minutes.\n",k++,h,m,dm);
	}
	return 0;
}

			
