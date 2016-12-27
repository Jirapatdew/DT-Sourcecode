#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,j;
    scanf("%d",&n);
    if(n<6) printf("no");
    else
    {
        printf("6");
        for(i=9;i<=n;i++)
        {
            if(i%3==0) printf("\n%d",i);
            else if(i%20==0) printf("\n%d",i);
            else
            {
                for(j=i-20;;j-=20)
                {
                    if(j<6) break;
                    if(j%3==0) {printf("\n%d",i); break;}
                }
            }
        }
    }
    return 0;
}
