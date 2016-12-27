#include <stdio.h>
#include <stdlib.h>
using namespace std;

int a[100010][2]={0},pt=1;
int chk[100010]={0};
int cmp(const void*a,const void*b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[0]<bb[0]) return 1;
    else return -1;
}
int main()
{
    int n,m,h;
    scanf("%d%d",&n,&m);
    chk[0]=1;chk[n+1]=1;///***///
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i][0]);
        a[i][1]=i;
    }
    qsort(a+1,n,sizeof(a[0]),cmp);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&h);
        int num=0;
        for(;a[pt][0]>h;pt++)
        {
            int id=a[pt][1];
            if(chk[id]!=0&&chk[id]<i) continue;
            if(chk[id]==0) num++;
            chk[a[pt][1]]=i;
            if(chk[id-1]==0) {num++;chk[id-1]=i;}
            if(chk[id+1]==0) {num++;chk[id+1]=i;}
        }
        printf("%d\n",num);
    }
    return 0;
}
