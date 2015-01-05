#include<stdio.h>

int main()
{
	long a,b,c,d,m,n,o,p;
    
    for(a=2;a<=200;a++)
    {
		m=a*a*a;
        for(b=2;b<=200;b++)
        {
            n=b*b*b;
            if(m<n)
			   break;
            for(c=b;c<=200;c++)
            {
			    o=c*c*c;
                if(m<n+o)
				    break;
			    for(d=c;d<=200;d++)
                {
                    p=d*d*d;
                    if(m<n+o+p)
					   break;
                    if(m==n+o+p)
                    {
				        printf("Cube = %ld, ",a);
                        printf("Triple = (%ld,%ld,%ld)\n",b,c,d);
                    }
                }
            }
		}
	}
    return 0;
}