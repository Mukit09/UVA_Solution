#include<stdio.h>
#include<algorithm>
#include<string>

using namespace std;

char a[2500][2500],st;
long R,C;
long cnt;

struct node 
{
    char ch;
	long f;
} p[2700];

void dfs(long r,long c)
{
    if(r<0||r==R||c<0||c==C||a[r][c]!=st) 
		return;

    cnt++;
    a[r][c]='.';
    dfs(r-1,c);
    dfs(r+1,c);
    dfs(r,c+1);
    dfs(r,c-1);
}

bool cmp(node x,node y)
{
    if(x.f>y.f) 
		return true;
    if(x.f==y.f&&x.ch<y.ch) 
		return true;

    return false;
}

int main ()
{
    long i,j,k=1,len;

    while(scanf("%d %d",&R,&C)&&(R||C)) 
	{
        for(i=0;i<R;i++) 
			scanf("%s",a[i]);

        len=0;

        for(i=0;i<R;i++) 
		{
            for(j=0;j<C;j++) 
			{
                if(a[i][j]!='.') 
				{
                    cnt=0;
					st=a[i][j];
                    p[len].ch=st;
                    dfs(i,j);
                    p[len].f=cnt;
					len++;
                }
            }
        }

        sort(p,p+len,cmp);

        printf("Problem %d:\n",k++);

        for (i=0;i<len;i++)
            printf("%c %d\n",p[i].ch,p[i].f);
    }
	return 0;
}
