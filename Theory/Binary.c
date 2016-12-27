#include <stdio.h>
#include <stdlib.h>
int n;
int ans[100]={0};
int binary(int a)
{
    int i;
    if(a<=n)
    {
        for(i=0;i<2;i++)
        {
            ans[a]=i;
            binary(a+1);
        }
    }
    else
    {
        for(i=1;i<=n;i++) printf("%d ",ans[i]);
        printf("\n");
        return 0;
    }
}
int main()
{
    scanf("%d",&n);
    binary(1);
    return 0;
}
