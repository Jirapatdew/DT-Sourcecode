#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    if(x>y) printf("2");
    else if(y%x==0) printf("%d",y/x);
    else printf("%d",y/x+1);
    return 0;
}
