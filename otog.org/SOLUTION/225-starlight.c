#include <stdio.h>
#include <stdlib.h>

int compare(const void*a,const void*b)
{
    int aa=*(int*)a;
    int bb=*(int*)b;
    if(aa>bb) return 1;
    else return -1;
}
int main()
{
    int s,n,i,maxx=0,maxy=0;
    int x[5005],y[5005];
    scanf("%d",&s);
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
    x[n]=0;
    x[n+1]=s;
    y[n]=0;
    y[n+1]=s;
    qsort(x,n+2,sizeof(x[0]),compare);
    qsort(y,n+2,sizeof(y[0]),compare);
    for(i=0;i<n+1;i++) if((x[i+1]-x[i])>maxx) maxx=x[i+1]-x[i];
    for(i=0;i<n+1;i++) if((y[i+1]-y[i])>maxy) maxy=y[i+1]-y[i];
    if(maxx<maxy) printf("%.3f",maxx/2.0);
    else printf("%.3f",maxy/2.0);
    return 0;
}
