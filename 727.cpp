#include<stdio.h>
#include<string.h>
#include<stack>

using namespace std;

stack<char>stk;

int main()
{
	char re[100],ch[15];
	long t,j,flag=0;
	scanf("%ld",&t);
	getchar();
	while(t--)
	{
		j=0;
		while(gets(ch))
		{
			if(flag)
			{	
				if(ch[0]=='\0')
					break;
				if(ch[0]=='+'||ch[0]=='-')
				{			
					if(stk.empty()==1)
						stk.push(ch[0]);
					else
					{
						while(stk.top()!='(')
						{
							re[j++]=stk.top();
							stk.pop();
							if(stk.empty()==1)
								break;
						}
						stk.push(ch[0]);
					}
				}
				else if(ch[0]=='*'||ch[0]=='('||ch[0]=='/')
				{
					if(stk.empty()==1)
						stk.push(ch[0]);
					else
					{
						if((stk.top()=='*'||stk.top()=='/')&&ch[0]!='(')
						{
							while(1)
							{
								if(stk.empty()==1||(stk.top()!='*'&&stk.top()!='/'))
									break;
								re[j++]=stk.top();
								stk.pop();
							}
						}
						stk.push(ch[0]);
					}
				}
				else if(ch[0]==')')
				{
					while(1)
					{
						if(stk.empty()==1)
							break;
						if(stk.top()=='(')
						{
							stk.pop();
							break;
						}
						else
						{
							re[j++]=stk.top();
							stk.pop();
						}
					}
				}
				else
					re[j++]=ch[0];
			}
			
			flag=1;	
		}
		while(1)
		{
			if(stk.empty()==1)
				break;
			re[j++]=stk.top();
			stk.pop();
		}
		re[j]=0;
		puts(re);
		if(t)
			printf("\n");
	}
	return 0;
}