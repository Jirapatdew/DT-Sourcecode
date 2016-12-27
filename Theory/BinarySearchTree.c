#include <stdio.h>
#include <stdlib.h>

int x,tree[10000],emp[10000]={0};
void binary(int k)
{
    if(emp[k]==0)
    {
        emp[k]=1;
        tree[k]=x;
        printf("*\n");
    }
    else
    {
        if(x>=tree[k]) {printf("R");binary(2*k+2); }
        else {printf("L");binary(2*k+1); }
    }
}
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        binary(0);
    }
    return 0;
}
