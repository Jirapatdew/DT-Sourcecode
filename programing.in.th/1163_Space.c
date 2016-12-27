#include <stdio.h>
#include <stdlib.h>

int n;
int ans[100]={0};

void print()
{
    int i;
    for(i=0;i<n;i++) printf("%d",ans[i]);
}
int binary(int a)
{
    int i;
    if(a<n)
    {
        for(i=0;i<2;i++)
        {
            ans[a]=i;
            binary(a+1);
        }
    }
    else
    {
        for(i=n-1;i>=0;i--)
        {
            if(ans[i]==0)
            {
                print();
                printf(" ");
                ans[i]=1;
                print();
                printf("\n");
                ans[i]=0;
            }
        }
    }
}
int main()
{

    scanf("%d",&n);
    binary(0);
    return 0;
}
