#include <stdio.h>
#include <stdlib.h>

using namespace std;

double fen[2][100050]={0};
int data[100050][2]={0};
int n;

double frqTO(int idx,int a)
{
    double sum=0;
    while(a>=1)
    {
        sum+=fen[idx][a];
        a-=(a&-a);
    }
    return sum;

}
void update(int idx,int a,int val)
{
    while(a<=n)
    {
        fen[idx][a]+=val;
        a+=(a&-a);
    }
}
int cmp(const void*a,const void*b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[0]<bb[0]) return 1;
    else return -1;
}
int main()
{
    double sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&data[i][0],&data[i][1]);
        update(0,data[i][1],1);
        update(1,data[i][1],data[i][0]);
    }
    qsort(&data[1],n,sizeof(data[0]),cmp);
    for(int i=1;i<=n;i++)
    {
        sum+=frqTO(1,n)-frqTO(1,data[i][1]);
        sum+=(frqTO(0,n)-frqTO(0,data[i][1]))*data[i][0];
        update(0,data[i][1],-1);
        update(1,data[i][1],-data[i][0]);
    }
    printf("%.0lf",sum);
    return 0;
}
