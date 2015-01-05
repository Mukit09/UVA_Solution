#include<stdio.h>
#include<string>
#include<string.h>
#include<map>
using namespace std;

map<string,long>mp;
string st;

int main()	 
{
	long i,j,k,l,m,a;
	
	a=0;
	for(i=97;i<=122;i++)
	{
	    st=i;
	    a++;
		mp[st]=a;
	}
	for(i=97;i<=121;i++)
	{
	    for(j=i+1;j<=122;j++)
		{
	        st=i;
	        st+=j;
	        a++;
			mp[st]=a;
	    }
	}
	for(i=97;i<=120;i++)
	{
	    for(j=i+1;j<=121;j++)
		{
	        for(k=j+1;k<=122;k++)
			{
	            st=i;
				st+=j;
				st+=k;
	            a++;
				mp[st]=a;
	        }
		}
	}
	for(i=97;i<=119;i++)
	{
	    for(j=i+1;j<=120;j++)
		{
	        for(k=j+1;k<=121;k++)
			{
	            for(l=k+1;l<=122;l++)
				{
	                st=i;
					st+=j;
					st+=k;
					st+=l;
	                a++;
					mp[st]=a;
	            }
			}
		}
	}
	for(i=97;i<=118;i++)
	{
	    for(j=i+1;j<=119;j++)
		{
	        for(k=j+1;k<=120;k++)
			{
	            for(l=k+1;l<=121;l++)
				{
	                for(m=l+1;m<=122;m++)
					{
	                    st=i;
	                    st+=j;
	                    st+=k;
	                    st+=l;
	                    st+=m;
	                    a++;
						mp[st]=a;
					}
				}
			}
		}
	}   
	char ch[10];
	long re;
	while(gets(ch))
	{
		re=mp[ch];
		printf("%ld\n",re);
	}
	return 0;
}