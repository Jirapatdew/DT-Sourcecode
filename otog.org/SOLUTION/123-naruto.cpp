#include <stdio.h>
#include <stdlib.h>
using namespace std;

int data[300050][2]={0},cnt=0;
int cmp(const void*a,const void*b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[0]>bb[0]) return 1;
    else return -1;
}
int main()
{
    int n,m;
    int a;
    scanf("%d%d",&n,&m);
    data[cnt][1]=-1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(data[cnt][1]==-1)
        {
            if(data[cnt][0]<a) data[cnt][0]=a;
            else
            {
                data[cnt][0]++;
                cnt++;
                data[cnt][0]=a;
                data[cnt][1]=1;
            }
        }
        else if(data[cnt][1]==1)
        {
            if(data[cnt][0]>a) data[cnt][0]=a;
            else
            {
                cnt++;
                data[cnt][0]=a;
                data[cnt][1]=-1;
            }
        }
    }
    if(data[cnt][1]==1) data[cnt][0]=0;
    else {data[cnt][0]++;cnt++;data[cnt][0]=0;data[cnt][1]=1;}
    qsort(data,cnt+1,sizeof(data[0]),cmp);
    int i=0;
    for(int j=1;j<=cnt;j++)
    {
        if(data[i][0]==data[j][0]) data[i][1]+=data[j][1];
        else
        {
            i++;
            data[i][0]=data[j][0];
            data[i][1]=data[i-1][1]+data[j][1];
        }
    }
    cnt=i;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&a);
        int lo=0,hi=cnt+1;
        int mid;
        while(lo<hi)
        {
            mid=(lo+hi)/2;
            if(data[mid][0]<a) lo=mid+1;
            else hi=mid;
        }
        if(lo==cnt+1) printf("0\n");
        else if(data[lo][0]==a) printf("%d\n",data[lo][1]);
        else printf("%d\n",data[lo-1][1]);
    }
    return 0;
}
