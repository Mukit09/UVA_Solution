#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,visit[30][30],ll;
char ch[30][30],res[500];

struct ss
{
	char st[500];
}stru[10010];

bool cmp(ss aa,ss bb)
{
//	if(strlen(aa.st)==strlen(bb.st))
		return aa.st<bb.st;
}

void dfs(int row,int col,int ind,char c)
{
	if(row<0||col<0||row==n||col==n)
		return ;
	if(visit[row][col])
		return ;

	visit[row][col]=1;
	res[ind]=ch[row][col];
	if(ind>=2)
	{
		int x;
		for(x=0;x<=ind;x++)
			stru[ll].st[x]=res[x];
		stru[ll++].st[x+1]=0;
	}

	if(ch[row+1][col]>c)
	{
//		visit[row+1][col]=1;
		dfs(row+1,col,ind+1,ch[row+1][col]);
//		visit[row+1][col]=0;
	}

	if(ch[row-1][col]>c)
	{
//		visit[row-1][col]=1;
		dfs(row-1,col,ind+1,ch[row-1][col]);
//		visit[row-1][col]=0;
	}

	if(ch[row][col+1]>c)
	{
//		visit[row][col+1]=1;
		dfs(row,col+1,ind+1,ch[row][col+1]);
//		visit[row][col+1]=0;
	}

	if(ch[row][col-1]>c)
	{
//		visit[row][col-1]=1;
		dfs(row,col-1,ind+1,ch[row][col-1]);
//		visit[row][col-1]=0;
	}

	if(ch[row+1][col+1]>c)
	{
//		visit[row+1][col+1]=1;
		dfs(row+1,col+1,ind+1,ch[row+1][col+1]);
//		visit[row+1][col+1]=0;
	}

	if(ch[row+1][col-1]>c)
	{
//		visit[row+1][col-1]=1;
		dfs(row+1,col-1,ind+1,ch[row+1][col-1]);
//		visit[row+1][col-1]=0;
	}

	if(ch[row-1][col+1]>c)
	{
//		visit[row-1][col+1]=1;
		dfs(row-1,col+1,ind+1,ch[row-1][col+1]);
//		visit[row-1][col+1]=0;
	}

	if(ch[row-1][col-1]>c)
	{
//		visit[row-1][col-1]=1;
		dfs(row-1,col-1,ind+1,ch[row-1][col-1]);
//		visit[row-1][col-1]=0;
	}
	visit[row][col]=0;
}

int main()
{
	int i,j,k,l;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%s",ch[i]);
			for(j=0;j<n;j++)
				visit[i][j]=0;
		}
		ll=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				dfs(i,j,0,ch[i][j]);
		/*		for(k=0;k<n;k++)
				{
					for(l=0;l<n;l++)
						visit[k][l]=0;
				}*/
			}
		}
		if(ll)
		{
			sort(stru,stru+ll,cmp);
			for(i=0;i<ll;i++)
				puts(stru[i].st);
		}
	}
	return 0;
}