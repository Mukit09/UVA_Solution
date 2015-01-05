#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define si 110
#define inf -9999999
#define fr(i,a,b) for(i=a;i<=b;i++)

vector<int>ve[si],vr[si];
int d[si],n,m,i,j,u,v,fg,l,chk[si],cst[si],sm,vis[si],tst;

struct ss
{
    int u,v;
}stru[si*si];


int dfs(int node)
{
    if(node==n)
    return 1;
    int i,u,l=ve[node].size(),ck=0;
    fr(i,0,l-1)
    {
        u=ve[node][i];
        if(chk[u]==0)
        {
            chk[u]=1;
            ck|=dfs(u);
        }
    }
    return ck;
}

int main()
{
  //  freopen("out.txt","w",stdout);
    while(~scanf("%d",&n)&&n!=-1)
    {
        l=1;
        tst=0;
        fr(i,1,n)
        {
            cst[i]=inf;
            chk[i]=vis[i]=0;
            scanf("%d%d",&d[i],&m);
            fr(j,1,m)
            {
                scanf("%d",&u);
                ve[i].push_back(u);
                vr[u].push_back(i);
                stru[l].u=i;
                stru[l].v=u;
                l++;
            }
        }
        cst[1]=100;
        fr(i,1,n-1)
        {
            fr(j,1,l-1)
            {
                u=stru[j].u;
                v=stru[j].v;

                if(cst[u]+d[v]>cst[v]&&cst[u]>0) // u negative hoar mane, 1 no node theke etate asa jai na
                cst[v]=cst[u]+d[v];
            }
        }
        fr(i,1,l-1)
        {
            u=stru[i].u;
            v=stru[i].v;
            if(cst[u]>0&&(cst[u]+d[v])>cst[v]&&dfs(u)) // u negative hoar mane, 1 no node theke etate asa jai na
            {
                tst=1;
                break;
            }
        }
        if(tst||cst[n]>0)
        puts("winnable");
        else
        puts("hopeless");
        fr(i,1,n)
        {
            ve[i].clear();
            vr[i].clear();
        }
    }
    return 0;
}
