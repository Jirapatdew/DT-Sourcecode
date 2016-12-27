#include <stdio.h>
#include <stdlib.h>

int input;
int chk[100]={0};
int ans[100];

int per(int n)
{
    int a,b;
    if(n<=input)
    {
        for(a=1;a<=input;a++)
        {
            if(chk[a]==0)
            {
                chk[a]=1;
                //for(b=1;b<=input;b++) printf("%d ",chk[b]);
                //printf("\n");
                ans[n]=a;
                per(n+1);
                chk[a]=0;
            }
        }
    }
    else
    {
        for(a=1;a<=input;a++) printf("%d ",ans[a]);
        printf("\n");
    }
}
int main()
{
    scanf("%d",&input);
    per(1);
    return 0;
}
