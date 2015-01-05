#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

map<string,long>mp;

char title[105];
char ch[1005],team1[40],team2[40];
char u[40],v[40];
long k;

struct ss
{
	char st[40];
	long g,w,l,ti,plcnt,point,gd,gsc,gag;
}T[40];

bool cmp(ss aa,ss bb)
{
	if(aa.point>bb.point) return true;
	else if(aa.point==bb.point)
	{
		if(aa.w>bb.w) return true;
		else if(aa.w==bb.w)
		{
			if(aa.gd>bb.gd) return true;
			else if(aa.gd==bb.gd)
			{
				if(aa.gsc>bb.gsc) return true;
				else if(aa.gsc==bb.gsc)
				{
					if(aa.g<bb.g) return true;
					else if(aa.g==bb.g)
					{
						strcpy(u,aa.st);
						strcpy(v,bb.st);
						for(k=0;u[k];k++)
						{
							if(u[k]>=65&&u[k]<=90)
								u[k]+=32;
						}
						for(k=0;v[k];k++)
						{
							if(v[k]>=65&&v[k]<=90)
								v[k]+=32;
						}
						if(strcmp(u,v)<=0)
							return true;
					}
				}
			}
		}
	}
	return false;
}
		
int main()
{
	long i,j,t,n,m,g1,g2,a1,a2;
	scanf("%ld",&t);
	getchar();
	while(t--)
	{
		for(i=0;i<35;i++)
		{
			T[i].g=0;
			T[i].w=0;
			T[i].l=0;
			T[i].ti=0;
			T[i].plcnt=0;
			T[i].point=0;
			T[i].gd=0;
			T[i].gsc=0;
			T[i].gag=0;
		}
		gets(title);
		scanf("%ld",&n);
		getchar();
		for(i=0;i<n;i++)
		{
			gets(T[i].st);
			mp[T[i].st]=i;
		}
		scanf("%ld",&m);
		getchar();
		while(m--)
		{
			gets(ch);
			i=0;
			while(ch[i]!='#')
			{
				team1[i]=ch[i];
				i++;
			}
			team1[i]=0;
			i++;
			g1=0;
			while(ch[i]>=48&&ch[i]<=57)
			{
				g1=g1*10+(ch[i]-48);
				i++;
			}
			g2=0;
			i++;
			while(ch[i]>=48&&ch[i]<=57)
			{
				g2=g2*10+(ch[i]-48);
				i++;
			}
			i++;
			j=0;
			while(ch[i])
			{
				team2[j]=ch[i];
				i++;
				j++;
			}
			team2[j]=0;
			a1=mp[team1];
			a2=mp[team2];
			T[a1].g++;
			T[a2].g++;
			T[a1].gsc+=g1;
			T[a2].gsc+=g2;
			T[a1].gag+=g2;
			T[a2].gag+=g1;
			T[a1].gd+=(g1-g2);
			T[a2].gd+=(g2-g1);
			if(g1>g2)
			{
				T[a1].point+=3;
				T[a1].w++;
				T[a2].l++;
			}
			else if(g1<g2)
			{
				T[a2].point+=3;
				T[a2].w++;
				T[a1].l++;
			}
			else 
			{
				T[a2].point++;
				T[a1].point++;
				T[a1].ti++;
				T[a2].ti++;
			}
		}
		sort(T,T+n,cmp);
		printf("%s\n",title);
		for(i=0;i<n;i++)
			printf("%ld) %s %ldp, %ldg (%ld-%ld-%ld), %ldgd (%ld-%ld)\n",i+1,T[i].st,T[i].point,T[i].g,T[i].w,T[i].ti,T[i].l,T[i].gd,T[i].gsc,T[i].gag);
		
		if(t)
			printf("\n");
		mp.clear();
	}
	return 0;
}
