#include <stdio.h>
#include <stdlib.h>

int ans[105]={0};
int run(int n,int a,int b,int k)
{
    int i;
    if(a==n||b==n)
    {
        for(i=0;i<k;i++)
        {
            if(ans[i]==1) printf("W ");
            else printf("L ");
        }
        printf("\n");return 0;

    }
    else
    {
        ans[k]=2;run(n,a,b+1,k+1);
        ans[k]=1;run(n,a+1,b,k+1);
        return 0;
    }
}
int main()
{
    int n,a,b;
    int i;
    scanf("%d%d%d",&n,&a,&b);
    run(n,a,b,0);
    return 0;
}
