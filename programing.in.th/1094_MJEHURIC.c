#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[10]={0};
    int i,j,tmp,p;
    for(i=0;i<5;i++) scanf("%d",&x[i]);
    while(1)
    {
        p=0;
        for(i=0;i<4;i++)
        {
            if(x[i]>x[i+1])
            {
                tmp=x[i];
                x[i]=x[i+1];
                x[i+1]=tmp;
                for(j=0;j<5;j++) printf("%d ",x[j]);
                printf("\n");
                p=1;
            }
        }
        if(p==0) break;
    }
    return 0;
}
