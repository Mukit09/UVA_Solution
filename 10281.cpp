#include<stdio.h>

int main() 
{
    int h,m,s,curspd=0,newspd,now,n,next=0;
    char curr[2000];
    double dist = 0;
   
    while(gets(curr))   
    {
        n = sscanf(curr,"%d:%d:%d %d",&h,&m,&s,&newspd);
        now = h * 3600 + m * 60 + s;
        dist += (now - next) / 3600.0 * curspd;
        next = now;
        if(n==3)
            printf("%02d:%02d:%02d %.2f km\n",h,m,s,dist);
        else
            curspd = newspd;
    }
    return 0;
}