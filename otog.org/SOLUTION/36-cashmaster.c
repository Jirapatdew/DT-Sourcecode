#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,a;
    int sum=0;//number can build between 1 to sum
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        if(sum+1<a) {printf("%d",sum+1);return 0;}
        else sum+=a;
    }
    printf("%d",sum+1);
    return 0;
}
