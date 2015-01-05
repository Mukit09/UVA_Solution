#include<stdio.h>
#include<string.h>
#define si 100
#define min(a,b) (a<b?a:b)
int dp[si][si],l1,l2,dir[si][si];
char ch1[si],ch2[si];

int rec(int i,int j)
{
	if(i==l1&&j==l2)
		return 0;
	else if(i==l1)
		return dp[i][j]=rec(i,j+1)+1;
	else if(j==l2)
		return dp[i][j]=rec(i+1,j)+1;
	int &ret=dp[i][j];
	if(ret!=-1)
		return ret;
	if(ch1[i]==ch2[j])
		ret=rec(i+1,j+1);
	else
	{
		ret=rec(i,j+1)+1;			// add
		ret=min(ret,rec(i+1,j)+1);  // del
		ret=min(ret,rec(i+1,j+1)+1);
	}
	return ret;
}

void path_prnt(int i,int j,int cnt)
{
	if(i==l1&&j==l2)
		return;
	else if(i==l1)  //add
	{
		printf("%d Insert %d,%c\n",cnt,j+1,ch2[j]);
		path_prnt(i,j+1,cnt+1);
		return ;
	}
	else if(j==l2)   //del
	{
		printf("%d Delete %d\n",cnt,j+1);
		path_prnt(i+1,j,cnt+1);
		return ;
	}
	if(ch1[i]==ch2[j])
		path_prnt(i+1,j+1,cnt);
	else
	{
		int p1=rec(i,j+1)+1;  //add
		int p2=rec(i+1,j)+1;  //del
		int p3=rec(i+1,j+1)+1;
		if(p1<=p2&&p1<=p3)
		{
			printf("%d Insert %d,%c\n",cnt,j+1,ch2[j]);
			path_prnt(i,j+1,cnt+1);
		}
		else if(p2<=p1&&p2<=p3)
		{
			printf("%d Delete %d\n",cnt,j+1);
			path_prnt(i+1,j,cnt+1);
		}
		else
		{
			printf("%d Replace %d,%c\n",cnt,j+1,ch2[j]);
			path_prnt(i+1,j+1,cnt+1);
		}
	}
}

int main()
{
	int i,j,fg=0;
	while(gets(ch1))
	{
		gets(ch2);
		if(fg)
			puts("");
		fg=1;
		l1=strlen(ch1);
		l2=strlen(ch2);
		for(i=0;i<l1;i++)
		{
			for(j=0;j<l2;j++)
				dp[i][j]=-1;
		}
		int ans=rec(0,0);
		printf("%d\n",ans);
		path_prnt(0,0,1);
	}
	return 0;
}