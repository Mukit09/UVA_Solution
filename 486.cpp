#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
using namespace std;
map<string,long>mp;
map<long,long>mp1;
char ch[10000],str[20],*pch;
long long  i,j,l,n,fg,sm,a[20],res;

int main()
{
   mp["zero"]=0;
   mp["one"]=1;
   mp["two"]=2;
   mp["three"]=3;
   mp["four"]=4;
   mp["five"]=5;
   mp["six"]=6;
   mp["seven"]=7;
   mp["eight"]=8;
   mp["nine"]=9;
   mp["ten"]=10;
   mp["eleven"]=11;
   mp["twelve"]=12;
   mp["thirteen"]=13;
   mp["fourteen"]=14;
   mp["fifteen"]=15;
   mp["sixteen"]=16;
   mp["seventeen"]=17;
   mp["eighteen"]=18;
   mp["nineteen"]=19;
   mp["twenty"]=20;
   mp["thirty"]=30;
   mp["forty"]=40;
   mp["fifty"]=50;
   mp["sixty"]=60;
   mp["seventy"]=70;
   mp["eighty"]=80;
   mp["ninety"]=90;
   mp["hundred"]=100;
   mp["thousand"]=1000;
   mp["million"]=1000000;
   mp1[100]=1;
   mp1[1000]=2;
   mp1[1000000]=3;
   while(gets(ch))
   {
      l=strlen(ch);
      res=sm=fg=0;
      for(i=0;i<l;i++)
      {
         if(ch[i]!=32)
            str[j++]=ch[i];
         if(ch[i]==32||i==l-1)
         {
			 if(ch[i]==32)
			 {
				 while(ch[i]==32&&i<l)
					 i++;
				 i--;
			 }
			 str[j]=0;
			 j=0;
             if(strcmp(str,"negative")==0)
                printf("-");
            
             else if(strcmp(str,"thousand")==0||strcmp(str,"million")==0)
			 {
				 sm+=res*mp[str];
				 res=0;
				 fg=1;
             }
			 else
			 {
				 if(strcmp(str,"hundred")==0)
					 res*=100;
				 else
					 res+=mp[str];
				 fg=0;
			 }
			 if(!fg&&i==l-1)
				 sm+=res;
         }
      }
      printf("%lld\n",sm);
   }
   return 0;
}
