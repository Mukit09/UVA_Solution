#include<stdio.h>
#include<string.h>

int main()
{
    int t,test,cs=1,w,b,a,n,i;
    char ch[50];
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%s",&n,ch);
        b=w=t=a=0;
        for(i=0;i<n;i++)
        {
            if(ch[i]=='B')
            b++;
            else if(ch[i]=='W')
            w++;
            if(ch[i]=='T')
            t++;
            else if(ch[i]=='A')
            a++;
        }
        printf("Case %d: ",cs++);
        if(a==n)
        puts("ABANDONED");
        else if(b+a==n)
        puts("BANGLAWASH");
        else if(w+a==n)
        puts("WHITEWASH");
        else if(w==b)
        printf("DRAW %d %d\n",w,t);
        else if(w>b)
        printf("WWW %d - %d\n",w,b);
        else
        printf("BANGLADESH %d - %d\n",b,w);
    }
    return 0;
}
