#include<stdio.h>
#define si 65
typedef unsigned long long i64;

i64 dp[si];
int n,back;

i64 rec(int i)
{
    if(i<=1)
    return 1;
    i64 &ret=dp[i];
    if(ret!=-1)
    return ret;
    int j;
    ret=0;
    for(j=1;j<=back;j++)
    ret+=rec(i-j);
    ret++;
    return ret;
}

int main()
{
    int i,x=1;
    while(~scanf("%d%d",&n,&back)&&n<=60)
    {
        if(back<0)
        {
            printf("Case %d: 1\n",x++);
            continue;
        }
        for(i=0;i<=n;i++)
        dp[i]=-1;
        printf("Case %d: %llu\n",x++,rec(n));
    }
}
