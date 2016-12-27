#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char in[50],a,x=1,i;
    scanf("%s",in);
    a=strlen(in);
    for(i=0;i<a;i++)
    {
        if(in[i]=='A')
        {
            if(x==2) x=1;
            else if(x==1) x=2;
        }
         if(in[i]=='B')
        {
            if(x==2) x=3;
            else if(x==3) x=2;
        }
         if(in[i]=='C')
        {
            if(x==1) x=3;
            else if(x==3) x=1;
        }
    }
    printf("%d",x);
    return 0;
}
