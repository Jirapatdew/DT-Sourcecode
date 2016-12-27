#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int p;
int cmp(const void* a,const void* b)
{
    int i;
    int *aa=(int*)a;
    int *bb=(int*)b;
    for(i=0; i<p; i++)
        if(aa[i]>bb[i]) return 1;
        else if(aa[i]<bb[i]) return -1;
}
int main()
{
    int n,i,j,a[100002][12]= {0},x[12],y[100002],u,l,c=0,d,key;
    int *begin;
    int *end;
    int *low;
    int *up;
    scanf("%d%d",&n,&p);
    for(i=0; i<n; i++)
        for(j=0; j<p; j++) scanf("%d",&a[i][j]);
    for(i=0; i<p; i++) scanf("%d",&x[i]);
    for(i=0; i<n; i++) a[i][11]=i+1;
    qsort(a,n,sizeof(a[0]),cmp);
    for(i=0; i<n; i++) y[i]=a[i][0];

    begin=&y[0];
    end=&y[n];
    low=lower_bound(begin,end,x[0]);
    up=upper_bound(begin,end,x[0]);
    u=up-begin;
    l=low-begin;
    for(i=l; i<u; i++)
    {
        c=0;
        for(j=1; j<p; j++)
        {
            if(a[i][j]==x[j]) c=1;
            else
            {
                c=0;
                break;
            }
        }
        if(c==1)
        {
            printf("%d",a[i][11]);
            break;
        }
    }
    if(c==0)
    {
        for(d=0; d<n; d++)
        {
            key=x[0]-y[d];
            if(key<0) break;
            low=lower_bound(begin,end,key);
            up=upper_bound(begin,end,key);
            u=up-begin;
            l=low-begin;
            for(i=l; i<u; i++)
            {
                c=0;
                for(j=1; j<p; j++)
                {
                    if(a[i][j]==x[j]-a[d][j]) c=1;
                    else
                    {
                        c=0;
                        break;
                    }
                }
                if(c==1)
                {
                    if(a[d][11]<a[i][11]) printf("%d %d",a[d][11],a[i][11]);
                    else if(a[d][11]>a[i][11]) printf("%d %d",a[i][11],a[d][11]);
                    else c=0;
                    break;
                }
            }
            if(c==1) break;
        }
        if(c==0) printf("NO");
    }
    return 0;
}
