#include<stdio.h>
#include<algorithm>
#define si 110
using namespace std;

long i,j,k,g,p,s,ii,jj,a[si][si],point[si];

struct ss
{
	long pos,marks;
}T[110];

bool cmp(ss aa,ss bb)
{
	if(aa.marks>bb.marks)
		return true;
	else if(aa.marks==bb.marks)
	{
		if(aa.pos<bb.pos) return true;
		else return false;
	}
	return false;
}

int main()
{
	long max;
	while(~scanf("%ld%ld",&g,&p)&&(g||p))
	{
		for(i=0;i<g;i++)
		{
			for(j=0;j<p;j++)
			{
				scanf("%ld",&jj);
				a[i][j]=jj-1;
				point[j]=0;
			}
		}
		scanf("%ld",&s);
		for(i=0;i<s;i++)
		{
			scanf("%ld",&k);
			for(ii=0;ii<p;ii++)
				point[ii]=T[ii].marks=T[i].pos=0;
			for(j=0;j<k;j++)
				scanf("%ld",&point[j]);
			max=0;
			for(ii=0;ii<g;ii++)
			{
				for(jj=0;jj<p;jj++)
				{
					T[jj].marks+=point[a[ii][jj]];
					T[jj].pos=jj+1;
					if(max<T[jj].marks)
						max=T[jj].marks;
				}
			}
			sort(T,T+jj,cmp);
			printf("%ld",T[0].pos);
			j=1;
			while(T[j].marks==max)
			{
				printf(" %ld",T[j].pos);
				j++;
			}
			printf("\n");
		}
	}
	return 0;
}
