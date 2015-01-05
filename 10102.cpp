#include<iostream>
#include<cstdio>
#define ABS(x) (((x)<0)?-(x):(x))
#define M 1010
using namespace std;

char Square[M][M];

int main()
{
    int dis,min,max;
    long N,i,j,k,l;

    while(scanf("%d\n",&N)==1)
    {
        for(i=0;i<N;i++)
            gets(Square[i]);

        max = 0;
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
                if(Square[i][j]=='1')
                {
                    min = 2147483647;
                    for(k=0;k<N;k++)
                        for(l=0;l<N;l++)
                            if(Square[k][l]=='3')
                            {
                                dis = ABS(i-k) + ABS(j-l);
                                if(dis<min)min=dis;
                            }
                    if(max<min)max = min;
                }
        printf("%d\n",max);
    }
    return 0;
}