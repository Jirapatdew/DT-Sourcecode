#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p,n,a,pa,pb,na=0,nb=0;
    int i;
    scanf("%d",&p);
    n=2*p;
    pa=pb=p;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        if(a%2==0)
        {
            nb=0;
            if(na>=2) pb-=3;
            else {pb-=1;na++;}
        }
        else
        {
            na=0;
            if(nb>=2) pa-=3;
            else {pa-=1;nb++;}
        }
        if(pa<=0) {printf("1\n");printf("%d\n",a);break;}
        else if(pb<=0) {printf("0\n");printf("%d\n",a);break;}
    }
    return 0;
}
