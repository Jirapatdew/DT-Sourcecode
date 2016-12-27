#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,total=0;
    scanf("%d%d%d",&a,&b,&c);
    while(a>1){a=a/2;total++;}
    while(b>1){b=b/2;total++;}
    while(c>1){c=c/2;total++;}
    printf("%d",total);
    return 0;
}
