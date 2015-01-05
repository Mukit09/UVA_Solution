#include<stdio.h>

int main()
{
    int a,b,c,cnt1,cnt0,one,zero;
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        cnt1=cnt0=0;
        if(a)
        {
            cnt1++;
            one=65;
        }
        else if(!a)
        {
            cnt0++;
            zero=65;
        }
        if(b)
        {
            cnt1++;
            one=66;
        }
        else if(!b)
        {
            cnt0++;
            zero=66;
        }
        if(c)
        {
            cnt1++;
            one=67;
        }
        else if(!c)
        {
            cnt0++;
            zero=67;
        }
        if(cnt1==3||cnt0==3)
        printf("*");
        else if(cnt1==1)
        printf("%c",one);
        else
        printf("%c",zero);
        printf("\n");
    }
}
