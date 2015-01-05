#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<map>
#include<string>
#include<string.h>
using namespace std;

#define si 50010
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)

int n,e,t,i,j,u,v,pu,pv,cst,r[si],p[si],k,ans;
char ch1[10],ch2[10];

map<string,int>mp;

struct ss
{
    int u,v,cst;
}stru[si];

bool cmp(ss aa,ss bb)
{
    return aa.cst<bb.cst;
}

int find(int x)
{
    if(p[x]==x)
        return x;
    else return p[x]=find(p[x]);
}

void link(int u,int v)
{
    if(r[u]>=r[v])
        p[v]=u,r[u]++;
    else
        p[u]=v,r[v]++;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&e);
        fr(i,1,n)
        {
            r[i]=1;
            p[i]=i;
        }
        j=1,k=0;
        while(e--)
        {
            scanf("%s%s%d",ch1,ch2,&cst);
            if(mp[ch1]==0)
                mp[ch1]=j++;
            if(mp[ch2]==0)
                mp[ch2]=j++;
            u=mp[ch1],v=mp[ch2];
            stru[k].u=u;
            stru[k].v=v;
            stru[k].cst=cst;
            k++;
        }
        sort(stru,stru+k,cmp);
        ans=0;
        rep(i,0,k)
        {
            pu=find(stru[i].u);
            pv=find(stru[i].v);
            if(pu!=pv)
            {
                link(pu,pv);
                ans+=stru[i].cst;
            }
        }
        printf("%d\n",ans);
        if(t)
            puts("");
        mp.clear();
    }
}
