/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 437 (496 - Simply Subsets) */
/* SUBMISSION: 09644196 */
/* SUBMISSION TIME: 2012-01-14 10:44:46 */
/* LANGUAGE: 3 */

#include<stdio.h>
#include<string.h>
#include<set>
#include<algorithm>

using namespace std;

set<long>s,ss;

long a,l,c1,c2,l1,l2,i,j,c,d;
char ch1[10005],ch2[10005],ch;

int main()
{
	
	while(gets(ch1))
	{
		gets(ch2);

		l1=strlen(ch1);
		c=0;
		d=0;
		for(i=0;i<l1;i++)
		{
			a=0;
			if(ch1[i]>47&&ch1[i]<58)
			{
				while(ch1[i]>47&&ch1[i]<58)
				{
					a=a*10+(ch1[i]-48);
					i++;
					c++;
				}
				s.insert(a);
			}
		}
		l=s.size();
		l2=strlen(ch2);
		for(j=0;j<l2;j++)
		{
			a=0;
			if(ch2[j]>47&&ch2[j]<58)
			{
				while(ch2[j]>47&&ch2[j]<58)
				{
					a=a*10+(ch2[j]-48);
					j++;
					d++;
				}
				ss.insert(a);
				s.insert(a);
			}
		}
		if(s.size()==ss.size()&&l==s.size())
		{
			puts("A equals B");
		}
		else if((l>ss.size()&&s.size()==ss.size())||(s.size()==ss.size()&&c>d)||l==s.size())
		{
			puts("B is a proper subset of A");
		}
		else if((l<ss.size()&&s.size()==ss.size())||(s.size()==ss.size()&&c<d))
		{
			puts("A is a proper subset of B");
		}
		else if(s.size()-l==ss.size())
		{
			puts("A and B are disjoint");
		}
		else
		{
			puts("I'm confused!");
		}
		s.clear();
		ss.clear();
	}
	return 0;
}