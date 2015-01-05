#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>
using namespace std;
map<string,long>mp;
  
int cnt,w[1110],m,fg,a[1110],chk[1110][1110],taken[1110],n,found;
char ch[1050];

void rec(int take,int ind,int nw)
{
	int i;
	if(take==m)
    {
		string st;
		for(i=0;i<=ind;i++)
		{
			if(taken[i]==1)
			{
				sprintf(ch,"%d",w[i]);
				st+=ch;
			}
		}
		if(mp[st]==0)
		{
			mp[st]=1;
			fg=1;
			for(i=0;i<=ind; i++)
			{
				if(taken[i]==1&&fg==1)
				{	
					printf("%d",w[i]);
					fg=0;
				}
				else if(taken[i]==1&&fg==0)
					printf("+%d",w[i]);
			}
			printf("\n");
			found=1;
		}
		return ;
	}
	for(i=ind;i<n;i++)
	{
		if(taken[i]==0&&chk[nw][i]==0&&w[i]+take<=m)
		{
			taken[i]=1;
			chk[nw][i]=1;
			rec(take+w[i],i+1,i);
			taken[i]=0;
			chk[nw][i]=0;
		}
	}

}

int main()
{
    int sum=0,i,j;
    while(~scanf("%d%d",&m,&n)&&n)
	{
		printf("Sums of %d:\n",m);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum<m)
		{
			printf("NONE\n");
			continue;
		}
		sort(a,a+n);
		for(i=n-1,j=0;i>=0;i--,j++)
			w[j]=a[i];
		
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
				chk[i][j]=0;
			chk[0][w[i]]=0;
		}
		found=0;
		rec(0,0,0);
		if(!found)
			puts("NONE");
		mp.clear();
	}
    return 0;
   
}

