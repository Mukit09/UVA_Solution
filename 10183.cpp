#include<stdio.h>
#include<string.h>
char a[200],b[200],c[200],d[510][200],sa[200],sb[200],sd[200];
long i,la,car,lb,ld,n,j,k;
int main()
{
	d[0][0]='0';
	d[0][1]=0;
	d[1][0]='1';
	d[1][1]=0;
	d[2][0]='1';
	d[2][1]=0;
	a[0]='1';
	a[1]=0;
	b[0]='1';
	b[1]=0;
	n-=2;
	for(n=3;n<500;n++)
	{
		la=strlen(a);
		car=0;
		for(i=0;i<la;i++)
		{
			if(a[i]<48)
				a[i]+=48;
			if(b[i]<48)
				b[i]+=48;
			c[i]=(a[i]-48)+(b[i]-48)+car;
			c[i]=c[i]+48;
			car=0;
			if(c[i]>57)
			{
				c[i]-=10;
				car=1;
			}
		}
		if(car==1)
		{
			c[i]=49;
			i++;
		}
		c[i]=0;
		strcpy(d[n],c);
		strcpy(b,a);
		strcpy(a,c);
	}
	while(1)
	{
		scanf("%s%s",sa,sb);
		if(!strcmp(sa,"0") && !strcmp(sb,"0"))
			break;
		car=0;
		la=strlen(sa);
		lb=strlen(sb);
		for(i=2;;i++)
		{
			ld=strlen(d[i]);
			if(ld>lb)
				break;
			if(ld<la)
				continue;
			k=0;
			for(j=ld-1;j>=0;j--)
				sd[k++]=d[i][j];
			sd[k]=0;
			ld=k;
			if(la==ld)
			{
				n=strcmp(sa,sd);
				if(n>0)
					continue;
				else
				{
					if(ld<lb)
						car++;
					else
					{
						n=strcmp(sb,sd);
						if(n>=0)
							car++;
						else
							break;
					}
				}
			}
			else
			{
				if(ld<lb)
					car++;
				else
				{
					n=strcmp(sb,sd);
					if(n>=0)
						car++;
					else
						break;
				}
			}
		}
		printf("%ld\n",car);
	}
	return 0;
}