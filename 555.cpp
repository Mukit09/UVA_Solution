#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

long dir[]={'S','W','N','E'};
long priority[100],priority1[100];

struct ss
{
	char card[5];
}n[15],s[15],e[15],w[15];

bool cmp(ss aa,ss bb)
{
	if(priority1[aa.card[0]]<priority1[bb.card[0]])
		return true;

	else if(aa.card[0]==bb.card[0])
		return priority[aa.card[1]]<priority[bb.card[1]];

	return false;
}

int main()
{
	char start[5],ch[100];
	long i,j,k,cnt,x;

	for(i=48;i<=85;i++)
		priority[i]=0;
	for(i=50;i<=57;i++)
		priority[i]=i;
	priority['T']=i++;
	priority['J']=i++;
	priority['Q']=i++;
	priority['K']=i++;
	priority['A']=i++;

	priority1['C']=i++;
	priority1['D']=i++;
	priority1['S']=i++;
	priority1['H']=i++;

	while(~scanf("%s",start))
	{
		if(strcmp(start,"#")==0)
			break;
		getchar();
		for(i=0;i<4;i++)
		{
			if(start[0]==dir[i])
				break;
		}
		j=(i+1)%4;
		cnt=x=0;
		for(i=1;i<=2;i++)
		{
			gets(ch);
			for(k=0;ch[k];k+=2)
			{
				if(j==0)
				{
					s[x].card[0]=ch[k];
					s[x].card[1]=ch[k+1];
					s[x].card[2]=0;
				}
				else if(j==1)
				{
					w[x].card[0]=ch[k];
					w[x].card[1]=ch[k+1];
					w[x].card[2]=0;
				}
				else if(j==2)
				{
					n[x].card[0]=ch[k];
					n[x].card[1]=ch[k+1];
					n[x].card[2]=0;
				}
				else if(j==3)
				{
					e[x].card[0]=ch[k];
					e[x].card[1]=ch[k+1];
					e[x].card[2]=0;
				}
				cnt++,j++;
				if(cnt==4)
					cnt=0,x++;
				if(j==4)
					j=0;
			}
		}
		sort(n,n+x,cmp);
		sort(s,s+x,cmp);
		sort(w,w+x,cmp);
		sort(e,e+x,cmp);

		printf("%c:",dir[0]);
		for(i=0;i<13;i++)
			printf(" %s",s[i].card);
		printf("\n");
		printf("%c:",dir[1]);
		for(i=0;i<13;i++)
			printf(" %s",w[i].card);
		printf("\n");
		printf("%c:",dir[2]);
		for(i=0;i<13;i++)
			printf(" %s",n[i].card);
		printf("\n");
		printf("%c:",dir[3]);
		for(i=0;i<13;i++)
			printf(" %s",e[i].card);
		printf("\n");
	}
	return 0;
}


		