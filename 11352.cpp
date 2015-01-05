#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
#define si 105
#define inf 999999
#define rep(i,a,b) for(i=a;i<b;i++)
queue<int>q;
char ch[si][si];
int cst_ki[si][si],cst_kn[si][si],vis_ki[si][si],vis_kn[si][si],n,m,fg;
int dx_kn[]={1,1,-1,-1,2,2,-2,-2};
int dy_kn[]={2,-2,2,-2,1,-1,1,-1};
int dx_ki[]={1,1,1,0,0,-1,-1,-1};
int dy_ki[]={1,-1,0,1,-1,1,-1,0};

void bfs_kn()
{
	int u,v,xx,yy,i;
	while(!q.empty())
	{
		xx=q.front();
		q.pop();
		yy=q.front();
		q.pop();
		vis_kn[xx][yy]=1;
		rep(i,0,8)
		{
			u=xx+dx_kn[i];
			v=yy+dy_kn[i];
			if(u>=0&&u<m&&v>=0&&v<n&&vis_kn[u][v]==0&&ch[u][v]!='A'&&ch[u][v]!='B'&&!cst_kn[xx][yy])
			{
				vis_kn[u][v]=1;
				cst_kn[u][v]=cst_kn[xx][yy]+1;
			}
		}
	}
}

void bfs_ki()
{
	int u,v,xx,yy,i;
	while(!q.empty())
	{
		xx=q.front();
		q.pop();
		yy=q.front();
		q.pop();
		vis_ki[xx][yy]=1;
		if(!fg)
		{
			for(i=0;i<8;i++)
			{
				u=xx+dx_ki[i];
				v=yy+dy_ki[i];
				if(u>=0&&u<m&&v>=0&&v<n&&vis_ki[u][v]==0&&cst_ki[xx][yy]+1<cst_kn[u][v])
				{
					vis_ki[u][v]=1;
					cst_ki[u][v]=cst_ki[xx][yy]+1;
					if(ch[u][v]=='B')
					{
						fg=1;
						break;
					}
					q.push(u);
					q.push(v);
				}
			}
		}
	}
}

int main()
{
	int t,i,j,edi,edj,sti,stj;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		for(i=0;i<m;i++)
		{
			scanf("%s",ch[i]);
			for(j=0;j<n;j++)
			{
				cst_ki[i][j]=cst_kn[i][j]=inf;
				vis_ki[i][j]=vis_kn[i][j]=0;
				if(ch[i][j]=='A')
				{
					cst_ki[i][j]=0;
					sti=i,stj=j;
				}
				else if(ch[i][j]=='B')
					edi=i,edj=j;
				else if(ch[i][j]=='Z')
				{
					q.push(i);
					q.push(j);
					cst_kn[i][j]=0;
					vis_kn[i][j]=1;
				}
			}
		}
		fg=0;
		bfs_kn();
		q.push(sti);
		q.push(stj);
		bfs_ki();
		if(fg)
			printf("Minimal possible length of a trip is %d\n",cst_ki[edi][edj]);
		else
			printf("King Peter, you can't go now!\n");
	}
	return 0;
}
		