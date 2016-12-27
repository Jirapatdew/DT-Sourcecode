#include <stdio.h>
#include <stdlib.h>
#define MAX(_x,_y) (((_x)>(_y))?(_x):(_y))
using namespace std;

int cmp(const void*a,const void*b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[0]>bb[0]) return 1;
    else if(aa[0]==bb[0]&&aa[1]<bb[1]) return 1;
    else return -1;
}
int main()
{
    int c;
    int n,a[400][2]={0};
    int p[400]={0};
    int val[400]={0};
    scanf("%d",&c);
    while(c>0)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d%d",&a[i][0],&a[i][1]);
        for(int i=0;i<n;i++) val[i]=p[i]=0;
        qsort(a,n,sizeof(a[0]),cmp);
        for(int i=0;i<n;i++)
        {
            val[i]=1;p[i]=a[i][1];
            for(int j=0;j<i;j++)
            {
                if(a[i][1]<=a[j][1])
                {
                    if(val[i]<val[j]+1)
                    {
                        val[i]=val[j]+1;
                        p[i]=a[j][1];
                    }
                    else if(val[i]==val[j]+1&&p[i]<a[j][1]) p[i]=a[j][i];
                }
                else if(a[i][0]>=a[j][i]&&p[j]>=a[i][1])
                {
                    if(val[i]<val[j]+1)
                    {
                        val[i]=val[j]+1;
                        p[i]=p[j];
                    }
                    else if(val[i]==val[j]&&p[i]<p[j]) p[i]=p[j];
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++) mx=MAX(mx,val[i]);
        printf("%d\n",mx);
        c--;
    }
    return 0;
}
