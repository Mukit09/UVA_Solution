#include<stdio.h>
#include<math.h>
#include<algorithm>
#define max(a,b) (a>b ?a:b)
#define si 510
using namespace std;

int r[si],p[si];
double x[si],y[si];

struct ss
{
	int beg,end,fg;
	double cst;
}stru[240610];

bool cmp(ss aa,ss bb)
{
	return aa.cst<bb.cst;
}

int find(int x)
{
	if(p[x]==x)
		return x;
	return p[x]=find(p[x]);
}

void link(int x,int y)
{
	if(r[x]>=r[y])
		p[y]=x,r[x]++;
	else
		p[x]=y,r[y]++;
}

int main()
{
	int t,i,j,k,st,po,pu,pv,cnt;
	double mx;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&st,&po);
		for(i=1;i<=po;i++)
		{
			r[i]=1;
			p[i]=i;
			scanf("%lf%lf",&x[i],&y[i]);
		}
		k=0;
		for(i=1;i<=po;i++)
		{
			for(j=i+1;j<=po;j++)
			{
				stru[k].beg=i;
				stru[k].end=j;
				stru[k].fg=0;
				stru[k].cst=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
				k++;
			}
		}
		sort(stru,stru+k,cmp);
		cnt=po-st;;
		for(i=0;i<k;i++)
		{
			pu=find(stru[i].beg);
			pv=find(stru[i].end);
			if(pu!=pv)
			{
				stru[i].fg=1;
				link(pu,pv);
				mx=stru[i].cst;
				cnt--;
				if(cnt==0)
					break;
			}
		}
		printf("%.2lf\n",sqrt(mx));
	}
	return 0;
}