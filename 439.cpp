#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
	long now,next,n,difc,difl,cnow,cnext;
	char ch1[15],ch2[15];
	while(~scanf("%s%s",ch1,ch2))
	{
		now=ch1[1]-48;
		cnow=ch1[0]-97;
		next=ch2[1]-48;
		cnext=ch2[0]-97;
		
		difc=abs(cnow-cnext);
		difl=abs(now-next);
	
		if(strcmp(ch1,ch2)==0)
			n=0;

		else if((difc==1&&difl==2)||(difc==2&&difl==1))
			n=1;

		else if((strcmp(ch1,"a1")==0&&strcmp(ch2,"b2")==0)||(strcmp(ch1,"b2")==0&&strcmp(ch2,"a1")==0))
			n=4;

		else if((strcmp(ch1,"h1")==0&&strcmp(ch2,"g2")==0)||(strcmp(ch1,"g2")==0&&strcmp(ch2,"h1")==0))
			n=4;

		else if((strcmp(ch1,"a8")==0&&strcmp(ch2,"b7")==0)||(strcmp(ch1,"b7")==0&&strcmp(ch2,"a8")==0))
			n=4;

		else if((strcmp(ch1,"h8")==0&&strcmp(ch2,"g7")==0)||(strcmp(ch1,"g7")==0&&strcmp(ch2,"h8")==0))
			n=4;

		else if((difc+difl==2)||(difc==1&&difl==3)||(difc==3&&difl==1)||(difc==2&&difl==4)||(difc==4&&difl==2)||(difc==3&&difl==3)||(difl==0&&difc==4)||(difl==4&&difc==0))
			n=2;

		else if((difc+difl)%4==0||(difc==1&&difl==5)||(difc==5&&difl==1)||(difc==0&&difl==6)||(difc==6&&difl==0)||(difc+difl==10))
			n=4;

		else if(difc==7&&difl==7)
			n=6;

		else if((difc+difl==1)||((difc+difl==7)&&(difc!=0&&difl!=0))||((difc+difl==9)&&(difc!=0&&difl!=0)&&(difc!=7&&difl!=7))||(difc+difl==5)||(difc==0&&difl==3)||(difc==3&&difl==0))
			n=3;

		else
			n=5;

		printf("To get from %s to %s takes %ld knight moves.\n",ch1,ch2,n);
		
	}
	return 0;
}