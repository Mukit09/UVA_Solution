#include<stdio.h>
#include<math.h>

#define sz 1000010

int a[sz];

int gcd(int a, int b)
{
    int tmp;
    while(b!=0)
    {
        tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}

int main()
{
    int i,j,x,y,z,n,cnt,sm,sq,tmpX,tmpY,tmpZ;
    while(~scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
        a[i]=0;

        cnt=sm=0;

        sq=sqrt(n);
        if(sq*sq<n)
        sq++;

        for(i=1;i<=sq;i++)
        {
            for(j=i+1;j<=sq;j++)
            {
                if(gcd(i,j)==1)
                {
                    x=j*j-i*i;
                    y=2*j*i;
                    z=j*j+i*i;
                    if(z>n)
                    break;

                    if(gcd(gcd(x,y),z)==1)
                    cnt++;

                    tmpX=x,tmpY=y,tmpZ=z;
                    while(tmpZ<=n)
                    {
                        a[tmpX]=a[tmpY]=a[tmpZ]=1;
                        tmpX+=x;
                        tmpY+=y;
                        tmpZ+=z;
                    }
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            if(a[i])
            sm++;
        }
        printf("%d %d\n",cnt,n-sm);
    }
    return 0;
}
