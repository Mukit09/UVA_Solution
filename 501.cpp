#include<stdio.h>
#include<set>
#include<iterator>
using namespace std;

#define sz 30010

int a[sz];

int main()
{
    int i,j,n,m,t,u,prev,fg,cnt;
    scanf("%d",&t);
    while(t--)
    {
        multiset<int>s;
        multiset<int>::iterator it;
        scanf("%d%d",&m,&n);

        for(i=1;i<=m;i++)
        scanf("%d",&a[i]);

        s.insert(a[1]);
        it=s.begin();
        cnt=1;
        fg=0;

        for(i=1;i<=n;i++)
        {
            scanf("%d",&u);
            while(cnt<u)
            {
                cnt++;
                s.insert(a[cnt]);
                if(a[cnt]<*it)
                it--;
            }
            if(fg)
            it++;
            printf("%d\n",*it);
            fg=1;
        }
        if(t)
        puts("");
    }
    return 0;
}
