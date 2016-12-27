#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i,p=0,a;
    int w=1,u=1,m=1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        if(p!=0)
        {
            if(a==p) w++;
            p=0;
        }
        if(a==10) u++;
        if(a==13) {p=10;m++;}
    }
    printf("%d %d %d",w,u,m);
    return 0;
}
