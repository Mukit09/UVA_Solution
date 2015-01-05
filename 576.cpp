#include<stdio.h>
#include<string.h>

long a[150];

int main()
{
	long l,i,j,flag,count;
	char ch[100000];
	for(i=0;i<=150;i++)
		a[i]=i;
	a['e']=a['i']=a['o']=a['u']=a['y']=97;
	while(gets(ch))
	{
		if(strcmp(ch,"e/o/i")==0)
			break;
		flag=j=0;
		l=strlen(ch);
		for(i=0;i<l;i++)
		{
			j++;
			count=0;
			while(ch[i]!='/'&&ch[i]!=0)
			{
				if(a[ch[i]]==97)
				{
					count++;
					while(a[ch[i]]==97)
					{
						i++;
						if(i==l)
							break;
					}
					i--;
				}
				i++;
				if(i==l)
					break;
			}
			if(j==1&&count!=5)
			{
				flag=1;
				break;
			}
			else if(j==2&&count!=7)
			{
				flag=1;
				break;
			}
			else if(j==3&&count!=5)
			{
				flag=1;
				break;
			}
		}
		if(flag)
			printf("%ld\n",j);
		else
			printf("Y\n");
	}
	return 0;
}