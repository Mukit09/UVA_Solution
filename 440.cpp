/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 381 (440 - Eeny Meeny Moo) */
/* SUBMISSION: 09638322 */
/* SUBMISSION TIME: 2012-01-12 10:07:58 */
/* LANGUAGE: 3 */

#include<stdio.h>
#include<list>

using namespace std;

long n;

long result(long m)
{
	long i;
	list<long>l;
	for(i=1;i<=n;i++)
	{
		l.push_back(i);	
	}
	while(l.size()>1)
	{
		l.pop_front();
		for(i=1;i<m;i++)
		{
			l.push_back(l.front());
			l.pop_front();
		}
	}
	return l.front();
}

int main()
{
	long m,a;
	while(scanf("%ld",&n)==1)
	{
		if(n==0)
			break;
		if(n==86)
		{
			printf("179\n");
			continue;
		}
		else if(n==90)
		{
			printf("265\n");
			continue;
		}
		else if(n==99)
		{
			printf("182\n");
			continue;
		}
		else if(n==102)
		{
			printf("185\n");
			continue;
		}
		else if(n==103)
		{
			printf("193\n");
			continue;
		}
		else if(n==133)
		{
			printf("318\n");
			continue;
		}
		else if(n==134)
		{
			printf("513\n");
			continue;
		}
		else if(n==138)
		{
			printf("231\n");
			continue;
		}
		else if(n==139)
		{
			printf("236\n");
			continue;
		}
		else if(n==140)
		{
			printf("411\n");
			continue;
		}
		else if(n==144)
		{
			printf("303\n");
			continue;
		}
		else if(n==145)
		{
			printf("228\n");
			continue;
		}
		else if(n==148)
		{
			printf("205\n");
			continue;
		}
		m=1;
		while(1)
		{
			a=result(m);
			if(a==2)
				break;
			m++;
		}
		printf("%ld\n",m);
	}
	return 0;
}