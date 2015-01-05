/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 1361 (10420 - List of Conquests) */
/* SUBMISSION: 09679081 */
/* SUBMISSION TIME: 2012-01-26 18:28:58 */
/* LANGUAGE: 3 */

#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int cmp(const void *a, const void *b)
{
	return strcmp( (char*) a, (char*) b);
}

int main()
{
	char ch[2010][80];
	char temp[100];

	long i,n,j;

	scanf("%ld",&n);

	for (i=0;i<n;i++)
	{
		scanf("%s",ch[i]);
		gets(temp);
	}

	qsort(ch,n,sizeof(ch[0]),cmp); 

	long count;
	for (i=0;i<n;i+=count)
	{
		count = 0;
		printf("%s ",ch[i]);
		for (j=i;j<n; j++)
		{
			if(strcmp(ch[i],ch[j]) == 0)
			{
				++count;
			}
		}
		printf("%ld\n",count);
	}
	return 0;
}