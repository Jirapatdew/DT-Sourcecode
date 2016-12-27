#include <stdio.h>
#include <stdlib.h>

int data[300010];
int main()
{
    int n,p;
    int Q,k,i;
    scanf("%d",&Q);
    for(k=0;k<Q;k++)
    {
        scanf("%d",&n);
        p=n;
        for(i=0;i<n;i++) scanf("%d",&data[i]);
        for(i=n-1;i>=0;i--)
        {
            if(data[i]==p) p--;
        }
        printf("%d\n",p);
    }

    return 0;
}
