#include<stdio.h>
#include<string.h>

long a[100];
long cnt[100],i,l,incr,decr,sum,fg,t;
char ch[550];

int main()
{
	a['B']=1;
	a['U']=10;
	a['S']=100;
	a['P']=1000;
	a['F']=10000;
	a['T']=100000;
	a['M']=1000000;

	scanf("%ld",&t);
	while(t--)
	{
		fg=cnt['B']=cnt['U']=cnt['S']=cnt['P']=cnt['F']=cnt['T']=cnt['M']=0;
		incr=decr=1;
		scanf("%s",ch);
		l=strlen(ch);
		sum=a[ch[0]];
		cnt[ch[0]]++;
		for(i=1;i<l;i++)
		{
			if(a[ch[i]]>=a[ch[i-1]])
				incr++;
			if(a[ch[i]]<=a[ch[i-1]])
				decr++;
			cnt[ch[i]]++;
			if(cnt[ch[i]]==10)
				fg=1;
			sum+=a[ch[i]];
		}
		if(incr!=l&&decr!=l)
			fg=1;
		if(fg)
			printf("error\n");
		else
			printf("%ld\n",sum);
	}
	return 0;
}