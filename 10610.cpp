#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;

// Define Some Variables
#define eps 1e-9
#define si 1010
#define pi acos(-1.0)
#define inf (1<<30)-1
#define mod 1000000000 //10^9

//Define Some Functions
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define dist(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

//typedef __int64 i64;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int i,j,l,vis[si],cst[si],ans,fg,k,m,v;
double x,y,stx,sty,edx,edy,f,mx,ds;
char ch[si];
queue<int>q;
vector<int>ve[si];

struct ss
{
	double x,y;
}stru[si];

void bfs()
{
	int ind,u;
	vis[0]=1;
	q.push(0);
	while(!q.empty())
	{
		ind=q.front();
		q.pop();
		l=ve[ind].size();
		rep(i,0,l)
		{
			u=ve[ind][i];
			if(vis[u]==0&&!fg)
			{
				vis[u]=1;
				cst[u]=cst[ind]+1;
				if(u==j-1)
				{
					fg=1;
					break;
				}
				q.push(u);
			}
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

   	while(~scanf("%d%d",&v,&m)&&(v||m))
   	{
		scanf("%lf%lf%lf%lf",&stx,&sty,&edx,&edy);
		getchar();
		j=1;
		fg=0;
		mx=v*m*60;
		mx*=mx;
		while(1)
		{
			gets(ch);
			if(strcmp(ch,"")==0)
				break;
			l=strlen(ch);
			
			i=y=0;
			sscanf(ch,"%lf%lf",&x,&y);
			stru[j].x=x;
			stru[j++].y=y;
		}
		stru[0].x=stx;
		stru[0].y=sty;
		stru[j].x=edx,stru[j++].y=edy;
		rep(i,0,j-1)
		{
			rep(k,i+1,j)
			{
				ds=dist(stru[i].x,stru[i].y,stru[k].x,stru[k].y);
				if(ds<mx||compare(ds,mx)==1)
				{
					ve[i].push_back(k);
					ve[k].push_back(i);
				}
			}
		}
		bfs();
		if(fg)
			printf("Yes, visiting %d other holes.\n",cst[j-1]-1);
		else
			puts("No.");
		rep(i,0,j)
		{
			ve[i].clear();
			vis[i]=cst[i]=0;
		}
    }
   	return 0;
}
