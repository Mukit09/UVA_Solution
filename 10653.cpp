#include<stdio.h>
#include<string.h>
#include<queue>
#include<stdlib.h>
using namespace std;
#define si 1010
#define inf 999999
queue<int>q;
int visit[si][si],cst[si][si],r,c,dx[]={0,0,-1,1},dy[]={-1,1,0,0};
char ch[10010];

void bfs(int x,int y)
{
	visit[x][y]=1;
	int i,xx,yy,nx,ny;
	q.push(x);
	q.push(y);
	while(!q.empty())
	{
		nx=q.front();
		q.pop();
		ny=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			xx=nx+dx[i];
			yy=ny+dy[i];
			if(xx>=0&&xx<r&&yy>=0&&yy<c&&visit[xx][yy]==0)
			{
				visit[xx][yy]=1;
				cst[xx][yy]=cst[nx][ny]+1;
				q.push(xx);
				q.push(yy);
			}
		}
	}
}

int main()
{
	int i,j,to,u,v,su,sv,du,dv,mine;
	while(~scanf("%d%d",&r,&c)&&(r||c))
	{
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				visit[i][j]=0;
				cst[i][j]=inf;
			}
		}
		scanf("%d",&to);
		while(to--)
		{
			scanf("%d%d",&u,&mine);

			for(i=1;i<=mine;i++)
			{
				scanf("%d",&v);
				visit[u][v]=1;
			}
		}
		scanf("%d%d",&su,&sv);
		cst[su][sv]=0;
		bfs(su,sv);
		scanf("%d%d",&du,&dv);
		printf("%d\n",cst[du][dv]);
	}
	return 0;
}
