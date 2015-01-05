/* USER: 93043 (mkbs_cse09) */
/* PROBLEM: 614 (673 - Parentheses Balance) */
/* SUBMISSION: 09663539 */
/* SUBMISSION TIME: 2012-01-20 19:02:57 */
/* LANGUAGE: 3 */

#include<stdio.h>
#include<stack>
#include<string.h>

using namespace std;

stack<char>stk;

long i,j,k,t,l,flag;

char ch[130];

int main()
{
	scanf("%ld",&t);
	getchar();
	for(k=1;k<=t;k++)
	{
		gets(ch);
		l=strlen(ch);
		flag=1;
		for(i=0;i<l;i++)
		{
			if(ch[i]=='('||ch[i]=='[')
			{
				stk.push(ch[i]);
			}
			else if(ch[i]==')')
			{
				if(stk.size()==0)
				{
					flag=0;
					break;
				}
				else if(stk.top()=='(')
				{
					stk.pop();
				}
			}
			else if(ch[i]==']')
			{
				if(stk.size()==0)
				{
					flag=0;
					break;
				}
				else if(stk.top()=='[')
				{
					stk.pop();
				}
			}
		}
		if(flag==1&&stk.size()==0)
		{
			printf("Yes\n");
		}
		else if(flag==0||stk.size()!=0)
		{
			printf("No\n");
		}
		while(!stk.empty())
		{
			stk.pop();
		}
	}
	return 0;
}