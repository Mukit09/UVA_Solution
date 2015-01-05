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
#define eps 1e-14
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
#define distance(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

//typedef __int64 i64;

int i,j,l,k,n,x=1,cnt,sm,fg,a[10],vowel[210],conso[210];
char ch[si];

int gcd(int a,int b)
{
    while(b>0)
    {
        a%=b;
        a^=b;
        b^=a;
        a^=b;
    }
    return a;
}

struct ss
{
	int c,ind;
}stru[30];

bool cmp(ss aa,ss bb)
{
	if(aa.c==bb.c)
		return aa.ind<bb.ind;
	return aa.c<bb.c;
}

int main()
{
	j=0;
	int jj,kk;
	rep(i,0,26)
	{
		if(i!=0&&i!=4&&i!=8&&i!=14&&i!=20)
		{
			stru[j].ind=i+1;
			stru[j].c=(i+1)%9;
			if(stru[j].c==0)
				stru[j].c=9;
			j++;
		}
	}
	sort(stru,stru+j,cmp);
	a[1]=1;
	a[2]=21;
	a[3]=5;
	a[4]=15;
	a[5]=9;
	int t;
	scanf("%d",&t);
   	while(t--)
   	{
		scanf("%d",&n);
		int vow=0;
		int con=0;
		j=1;
		k=0;
		jj=kk=0;
		printf("Case %d: ",x++);
		FOR(i,1,n)
		{
			if(odd(i))
			{
				vow++;
				vowel[jj++]=a[j];
				if(vow%21==0)
					j++;
			}
			else
			{
				con++;
				conso[kk++]=stru[k].ind;
				if(con%5==0)
					k++;
			}
		}
		sort(vowel,vowel+jj);
		sort(conso,conso+kk);
		jj=kk=0;
		FOR(i,1,n)
		{
			if(odd(i))
				printf("%c",vowel[jj++]+64);
			else
				printf("%c",conso[kk++]+64);
		}
		puts("");
    }
   	return 0;
}