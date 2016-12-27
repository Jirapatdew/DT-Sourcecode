#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[5][4],i,j,a,c;
    for(i=0; i<5; i++)
        for(j=0; j<4; j++)
            scanf("%d",&x[i][j]);
    for(i=0; i<5; i++)
        for(j=1; j<4; j++)
            x[i][0]=x[i][0]+x[i][j];
    for(i=0; i<5; i++)
        if(x[0][0]<=x[i][0])
        {
            a=i;
            x[0][0]=x[i][0];
        }
    printf("%d %d",a+1,x[0][0]);

    return 0;
}
