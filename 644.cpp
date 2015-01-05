#include<stdio.h>
#include<string>
#include<string.h>
#include<map>
using namespace std;

map<string,long>mp;
char ch[10][15],st[15];
long t,k,i,j,fg,x;

int main()
{
	k=1,t=1;
	while(scanf("%s",ch[k])!=EOF)
	{
		if(!strcmp(ch[k],"9"))
		{
			fg=0;
			for(i=1;i<k;i++)
			{
				x=0;
				for(j=0;ch[i][j];j++)
				{
					st[x++]=ch[i][j];
					st[x]=0;
					if(mp[st]&&strcmp(ch[i],st))
					{
						fg=1;
						break;
					}
				}
				if(fg)
					break;
			}
			if(fg)
				printf("Set %ld is not immediately decodable\n",t++);
			else
				printf("Set %ld is immediately decodable\n",t++);
			k=1;
			mp.clear();
			continue;
		}
		mp[ch[k]]=1;
		k++;
	}
	return 0;
}
