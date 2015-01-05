#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
int main()
{
    char ch[50];
    long t,j=1,l;
	scanf("%ld",&t);
	getchar();
	while(t--)
    {
		gets(ch);
		l=strlen(ch);
        sort(ch,ch+l);
		while(1)
        {
            printf("%s\n",ch);
			if(next_permutation(ch,ch+l)==0)
				break;
        }
		printf("\n");
    }
    return 0;
}