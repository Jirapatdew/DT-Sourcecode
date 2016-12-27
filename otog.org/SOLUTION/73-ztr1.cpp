#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define MAX(a,b) (a>b)?a:b
using namespace std;

int a[100050][3]={0};
int time[100050]={0},cnt=2;
int val[100050]={0};
int cmp(const void*a,const void*b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[1]>bb[1]) return 1;
    else return -1;
}
int main()
{
    int n,p=0,mx=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
    qsort(a,n,sizeof(a[0]),cmp);
    time[1]=a[0][1];
    val[1]=a[0][2];
    for(int i=1;i<n;i++)
    {
        int *x;
        if(cnt==2&&a[i][1]==time[1])
        {
            if(val[1]<a[i][2]) val[1]=a[i][2];
        }
        else
        {
            if(a[i][1]==time[cnt-1]) cnt--;
            else time[cnt]=a[i][1];
            x=lower_bound(time+1,time+cnt,a[i][0]);
            val[cnt]=MAX(val[cnt],val[cnt-1]);
            val[cnt]=MAX(val[cnt],val[(x-time)-1]+a[i][2]);
            cnt++;
        }
    }
    printf("%d",val[cnt-1]);
    return 0;
}
