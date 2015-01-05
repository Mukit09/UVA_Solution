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

//Define Some Functions
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define distance(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define FOR1(i,a,b) for(i=a;i<=b;i++)
#define FOR0(i,a,b) for(i=a;i<b;i++)
#define REV(i,a,b)  for(i=a;i>=b;i--)

//typedef __int64 i64;

int i,j,l,n,x=1,sm,cnt,fg,a[si];
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
	string st;
	int cst;
}stru[si];

bool cmp(ss aa,ss bb)
{
	if(aa.cst==bb.cst)
		return aa.st<bb.st;
	return aa.cst<bb.cst;
}

int main()
{
	int t,m,ll,k,sma,smb,ans,chk,p;
	scanf("%d",&t);
    while(t--)
    {
		scanf("%d%d%d",&n,&m,&l);
		while(getchar()!='\n');
		sm=cnt=0;
		fg=1;
		FOR0(i,0,l)
		{
			gets(ch);
			ll=strlen(ch);
			k=0;
			string st;
			FOR0(k,0,ll)
			{
				if(ch[k]==':')
					break;
				st+=ch[k];
			}
			stru[i].st=st;
			j=k+1;
			sma=0;
			FOR0(k,j,ll)
			{
				if(ch[k]==',')
					break;
				sma=sma*10+(ch[k]-48);
			}
			j=k+1;
			smb=0;
			FOR0(k,j,ll)
				smb=smb*10+(ch[k]-48);
			ans=0;
			int nn=n,mm=2*m;
			while(1)
			{
				chk=nn/2;
				if(chk<m)
				{
					p=nn-m;
					p=p*sma;
					ans+=p;
					break;
				}
				p=nn-chk;
				p=p*sma;
				if(p<smb)
					ans+=p;
				else
					ans+=smb;
				nn=chk;
			}
			stru[i].cst=ans;
		}
		sort(stru,stru+l,cmp);
		printf("Case %d\n",x++);
		FOR0(i,0,l)
			cout<<stru[i].st<<" "<<stru[i].cst<<endl;
	}		
    return 0;
}