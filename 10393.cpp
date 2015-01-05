#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
map<string,long>mp;

string st;

struct ss
{
	string ch;
	long len;
}T[1030];

bool cmp(ss aa,ss bb)
{
	if(aa.len>bb.len) return true;
	else if(aa.len==bb.len)
	{
		if(aa.ch<bb.ch) return true;
	}
	return false;
}

int main()
{
	long i,f,n,b,a[15],q,l,j,fg,max,k,cnt;
	long let[250];
	let['q']=let['a']=let['z']=1;
	let['w']=let['s']=let['x']=2;
	let['e']=let['d']=let['c']=3;
	let['r']=let['f']=let['v']=let['t']=let['g']=let['b']=4;
	let[' ']=5;
	let[' ']=6;
	let['y']=let['h']=let['n']=let['u']=let['j']=let['m']=7;
	let['i']=let['k']=8;
	let['o']=let['l']=9;
	let['p']=let[';']=let['/']=10;

	while(~scanf("%ld%ld",&f,&n))
	{
		for(i=1;i<=10;i++)
			a[i]=0;
		for(i=1;i<=f;i++)
		{
			scanf("%ld",&b);
			a[b]=1;
		}
		cnt=max=j=0;
		getchar();
		for(k=0;k<n;k++)
		{
			cin>>st;
			l=st.length();
			fg=1;
			for(i=0;i<l;i++)
			{
				if(a[let[st[i]]])
				{
					fg=0;
					break;
				}
			}
			if(fg&&mp[st]==0)
			{
				T[j].ch=st;
				T[j++].len=l;
				if(l==max)
					cnt++;
				if(l>max)
				{
					max=l;
					cnt=1;
				}
				mp[st]=1;
			}
		}
		sort(T,T+j,cmp);
		i=0;
		printf("%ld\n",cnt);
		while(max==T[i].len&&max!=0)
		{
			cout<<T[i].ch<<endl;
			i++;
		}
		mp.clear();
	}
	return 0;
}

