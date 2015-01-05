//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
long ind[500];
int main()
{
	char ch;
	long t,cs=1,m,n,i,j;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&m,&n);
		for(i=0;i<m;i++)
		{
			getchar();
			for(j=0;j<n;j++)
			{
				ch=getchar();
				if(ch=='@'||ch=='I'||ch=='E'||ch=='H'||ch=='O'||ch=='V'||ch=='A'||ch=='#')
					ind[ch]=j;
			}
		}
		if(ind['I']==ind['@'])
			printf("forth");
		else if(ind['I']<ind['@'])
			printf("left");
		else
			printf("right");

		if(ind['E']==ind['I'])
			printf(" forth");
		else if(ind['E']<ind['I'])
			printf(" left");
		else
			printf(" right");

		if(ind['H']==ind['E'])
			printf(" forth");
		else if(ind['H']<ind['E'])
			printf(" left");
		else
			printf(" right");

		if(ind['O']==ind['H'])
			printf(" forth");
		else if(ind['O']<ind['H'])
			printf(" left");
		else
			printf(" right");

		if(ind['V']==ind['O'])
			printf(" forth");
		else if(ind['V']<ind['O'])
			printf(" left");
		else
			printf(" right");

		if(ind['A']==ind['V'])
			printf(" forth");
		else if(ind['A']<ind['V'])
			printf(" left");
		else
			printf(" right");

		if(ind['#']==ind['A'])
			printf(" forth");
		else if(ind['#']<ind['A'])
			printf(" left");
		else
			printf(" right");

		printf("\n");
	}
	return 0;
}