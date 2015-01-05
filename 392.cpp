#include<stdio.h>
#include<string.h>

long i,fg,a[15],flag;
char ch[10][10];

int main()
{
	strcpy(ch[1],"x^8");
	strcpy(ch[2],"x^7");
	strcpy(ch[3],"x^6");
	strcpy(ch[4],"x^5");
	strcpy(ch[5],"x^4");
	strcpy(ch[6],"x^3");
	strcpy(ch[7],"x^2");
	strcpy(ch[8],"x");
	while(~scanf("%ld%ld%ld%ld%ld%ld%ld%ld%ld",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9]))
	{
		fg=flag=0;
		for(i=1;i<=8;i++)
		{
			if(a[i]<0&&fg)
			{
				a[i]=-a[i];
				printf(" -");
			}
			else if(a[i]>0&&fg)
				printf(" +");
				
			if(a[i]>1&&fg==1)
			{
				printf(" %ld%s",a[i],ch[i]);
			}
			else if(a[i]==1&&fg==1)
			{
				printf(" %s",ch[i]);
			}
			if((a[i]>1||a[i]<-1)&&fg==0)
			{
				printf("%ld%s",a[i],ch[i]);
				fg=1;
				flag=1;
			}
			else if((a[i]==1||a[i]==-1)&&fg==0)
			{
				fg=1;
				if(a[i]==-1)
					printf("-%s",ch[i]);
				else
					printf("%s",ch[i]);
				flag=1;
			}
		}
		if(flag)
		{
			if(a[i]==0)
			{
				printf("\n");
				continue;
			}
			if(a[i]<0)
			{
				a[i]=-a[i];
				printf(" - ");
			}
			else
				printf(" + ");
			printf("%ld\n",a[i]);
		}
		else
			printf("%ld\n",a[i]);
	}
	return 0;
}