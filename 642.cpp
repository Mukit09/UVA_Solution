#include<stdio.h>
#include<map>
#include<algorithm>
#include<string.h>
#include<string>

using namespace std;

map<string,long>mp;

int main()
{
	long i,j,l,k,fg;
	char ch[10];
	while(~scanf("%s",ch))
	{
		if(!strcmp(ch,"XXXXXX"))
		{
			while(~scanf("%s",ch))
			{
				if(!strcmp(ch,"XXXXXX"))
					break;
				fg=1;
				l=strlen(ch);
				sort(ch,ch+l);
				do
				{
					if(mp[ch]!=0)
					{
						printf("%s\n",ch);
						fg=0;
					}
				}while(next_permutation(ch,ch+l));
				if(fg)
					printf("NOT A VALID WORD\n");
				printf("******\n");
			}
			break;
		}
		mp[ch]++;
	}
	return 0;
}

