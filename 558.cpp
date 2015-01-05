#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

#define si 2010
#define inf 999999

vector<int>ve[si];

struct ss
{
    int u,v,w;
}stru[si];

int d[si];

int main()
{
    int n,m,i,j,u,v,w,fg,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        fg=1;

        for(i=1;i<=n;i++)
        d[i]=inf;

        int s;

        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&stru[i].u,&stru[i].v,&stru[i].w);
            stru[i].u++;
            stru[i].v++;
        }

        d[1]=0;

        for(i=1;i<n;i++)
        {
            for(j=1;j<=m;j++)
            {
                u=stru[j].u;
                v=stru[j].v;
                w=stru[j].w;

                if(d[u]+w<d[v])
                d[v]=d[u]+w;
            }
        }

        for(i=1;i<=m;i++)
        {
            u=stru[i].u;
            v=stru[i].v;
            w=stru[i].w;

            if(d[u]+w<d[v])
            {
                fg=0;
                break;
            }
        }
        if(!fg)
        puts("possible");
        else
        puts("not possible");
    }
    return 0;
}
