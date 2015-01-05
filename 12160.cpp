#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
using namespace std;

#define si 1010
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)

int n,i,j,k,l,cst[11][11][11][11],fg,x=1;
char st[7],ed[7],ch[7],str[8],ad[12][7];
queue<char>q;

int check(char w,char x,char y,char z)
{
    if(cst[w-48][x-48][y-48][z-48]==-1)
        return 1;
    return 0;
}

void fill(char w,char x,char y,char z,int t)
{
    cst[w-48][x-48][y-48][z-48]=t+1;
    if(w==ed[0]&&x==ed[1]&&y==ed[2]&&z==ed[3])
        fg=1;

    if(fg)
        return;
    q.push(w);
    q.push(x);
    q.push(y);
    q.push(z);
}

void bfs()
{
    int i,num,t,cry,m;
    char w,x,y,z;
    q.push(st[0]);
    q.push(st[1]);
    q.push(st[2]);
    q.push(st[3]);
    cst[st[0]-48][st[1]-48][st[2]-48][st[3]-48]=0;
    while(!q.empty())
    {
        w=q.front();ch[0]=w;
        q.pop();
        x=q.front();ch[1]=x;
        q.pop();
        y=q.front();ch[2]=y;
        q.pop();
        z=q.front();ch[3]=z;
        q.pop();
        ch[4]=0;
        if(!fg)
        {
            t=cst[ch[0]-48][ch[1]-48][ch[2]-48][ch[3]-48];
            sscanf(ch,"%d",&num);
            str[0]=str[1]=str[2]=str[3]='*';
            fr(i,1,n)
            {
                cry=0;
                for(j=3;j>=0;j--)
                {
                    m=ad[i][j]+ch[j]+cry-48;
                    if(m>57)
                        m-=10,cry=1;
                    else
                        cry=0;
                    str[j]=m;
                }
                if(check(str[0],str[1],str[2],str[3])==1)
                    fill(str[0],str[1],str[2],str[3],t);

                if(fg)
                    break;
            }
        }
    }
}

int main()
{
    while(~scanf("%s%s%d",&st,&ed,&n))
    {
        if(strcmp(st,"0")==0&&strcmp(ed,"0")==0&&n==0)
            break;

        fr(i,1,n)
            scanf("%s",ad[i]);
        if(strcmp(st,ed)==0)
        {
            printf("Case %d: 0\n",x++);
            continue;
        }
        rep(i,0,10)
        {
            rep(j,0,10)
            {
                rep(k,0,10)
                {
                    rep(l,0,10)
                        cst[i][j][k][l]=-1;
                }
            }
        }
        fg=0;
        bfs();
        if(!fg)
            printf("Case %d: Permanently Locked\n",x++);
        else
            printf("Case %d: %d\n",x++,cst[ed[0]-48][ed[1]-48][ed[2]-48][ed[3]-48]);
    }
    return 0;
}
