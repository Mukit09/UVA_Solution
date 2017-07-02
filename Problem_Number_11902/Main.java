package Problem_Number_11902;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	final static int SIZE=110;
	
	static ArrayList<ArrayList<Integer>> list=new ArrayList();
	static ArrayList<Integer> list1=new ArrayList();
	static int vis[]=new int[SIZE], curr;
	static int mat[][]=new int[SIZE][SIZE];
	static StringBuilder sBuilder;
	
	public static void dfs(int node) {
		
		vis[node]=1;
		list1.add(node);
		int l=list.get(node).size();
		int i,v;
		for(i=0;i<l;i++) {
			
			v=list.get(node).get(i);
			if(vis[v]==0) {
				
				vis[v]=1;
				dfs(v);
			}
		}
	}
	
	static void dfs1(int node) {
		
		vis[node]=1;
		int i,u,l=list.get(node).size();
		for(i=0;i<l;i++) {
			
			u=list.get(node).get(i);
			if(vis[u]==0 && u!=curr) {
				
				vis[u]=1;
				dfs1(u);
			}
		}
	}

	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
	//	PrintWriter pWriter=new PrintWriter(System.out);
		
		int t=sc.nextInt(),n;
		int i,j,v,cnt,x,y,cs=1;
		char ch;
		while(t-->0) {
			
			sBuilder=new StringBuilder();
			n=sc.nextInt();
			
			for(i=0;i<n;i++) {
				
				ArrayList<Integer> tmpList=new ArrayList();
				vis[i]=0;
				for(j=0;j<n;j++) {
					
					v=sc.nextInt();
					if(v==1)
						tmpList.add(j);
					mat[i][j]=0;
				}
				list.add(tmpList);
			}
			
			dfs(0);
			
			for(i=0;i<list1.size();i++) {
				
				for(j=0;j<list1.size();j++)
					vis[list1.get(j)]=0;
				
				curr=list1.get(i);
				if(curr!=0)
					dfs1(0);
				
				for(j=0;j<list1.size();j++) {
					
					if(vis[list1.get(j)]==0) 
						mat[curr][list1.get(j)]=1;
				}
			}
			System.out.println("Case " + cs++ + ":");
			for(i=0;i<2*n+1;i++) {
				
				for(j=0;j<2*n+1;j++) {
					
					if(i%2==0) {
						
						if(j==0||j==2*n) {
							
							sBuilder.append('+');
						//	pWriter.print('+');
						}
						else {
							
							sBuilder.append('-');
						//	pWriter.print('-');
						}
					}
					else {
						
						if(j%2==0) {
							
							sBuilder.append('|');
						//	pWriter.print('|');
						}
						else {
							
							x=i/2;
							y=j/2;
							ch=mat[x][y]==1?'Y':'N';
							sBuilder.append(ch);
						//	pWriter.print(ch);
						}
					}
				}
				sBuilder.append('\n');
			//	pWriter.print('\n');
			}
			System.out.print(sBuilder.toString());
			list1.clear();
			list.clear();
		//	pWriter.flush();
		}
	}
}
