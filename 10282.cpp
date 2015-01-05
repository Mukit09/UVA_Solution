#include <iostream>  
#include <string>  
#include <map>  
  
using namespace std; 

map<string,string>m; 
  
int main()
{  
	 long i,j,k;  
	 char s[11],ss[11],line[25];  
     
	 while( gets(line) )
	 {  
		  if( strcmp(line,"") )
		  {  
			   sscanf(line,"%s %s",&s,&ss);  
			   if( m[ss] == "" )  
					m[ss] = s;  
		  }  
		  else
		  {  
			   while( gets(line) )
			   {  
				if( m[line] != "" )  
					cout << m[line] << '\n';  
				else  
					 cout << "eh\n";  
			   }  
		  }  
	 }   
	 return 0;  
} 