#include<stdio.h>
#include<string.h>

long i,j,n,k,l,cnt;
char ch[110][110],res[20][30];

int main()
{
	strcpy(res[1],"Happy");
	strcpy(res[2],"birthday");
	strcpy(res[3],"to");
	strcpy(res[4],"you");
	strcpy(res[5],"Happy");
	strcpy(res[6],"birthday");
	strcpy(res[7],"to");
	strcpy(res[8],"you");
	strcpy(res[9],"Happy");
	strcpy(res[10],"birthday");
	strcpy(res[11],"to");
	strcpy(res[12],"Rujia");
	strcpy(res[13],"Happy");
	strcpy(res[14],"birthday");
	strcpy(res[15],"to");
	strcpy(res[16],"you");
	scanf("%ld",&n);
	for(i=1;i<=n;i++)
		scanf("%s",ch[i]);
	i=j=1;
	cnt=0;
	while(1)
	{
		k=j%17;
		if(k==0)
		{
			j=1;
			k=1;
		}
		l=i%(n+1);
		if(l==0)
		{
			i=1;
			l=1;
		}
		printf("%s: %s\n",ch[l],res[k]);
		if(cnt>=n&&k==16)
			break;
		i++;
		j++;
		cnt++;
	}
	return 0;
}

