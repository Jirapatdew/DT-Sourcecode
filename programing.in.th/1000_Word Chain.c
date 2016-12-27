#include <stdio.h>
#include <stdlib.h>

int main()
{
    int l,n,i,j,count=0,k;
    char x[1001]={'\0'},y[1001]={'\0'},z[1001]={'\0'};
    scanf("%d%d",&l,&n);
    scanf("%s",x);
    for(i=1;i<n;i++)
    {
        scanf("%s",y);
        for(j=0;j<l;j++) if(x[j]==y[j]) ++count;
        if(count>=l-2) for(j=0;j<l;j++) z[j]=y[j];
        else
        {
            for(j=0;j<l;j++) z[j]=x[j];
            for(k=i+1;k<n;k++) scanf("%s",y);
            break;
        }
        count=0;
        for(j=0;j<l;j++) x[j]=y[j];
    }
    if(n==1) printf("%s",x);
    else printf("%s",z);
    return 0;
}



