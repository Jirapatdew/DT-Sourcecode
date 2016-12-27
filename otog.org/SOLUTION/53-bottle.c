#include <stdio.h>
#include <stdlib.h>

int a[100005][2]= {0};
int use[100005]= {0};
int cmp(const void*a,const void*b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[0]<bb[0]) return 1;
    else return -1;
}
int del(int x,int i)
{
    int sum=0;
    if(use[x]==0){use[x]=i;sum++;}
    if(use[x-1]==0&&use[x]==i){use[x-1]=i;sum++;}
    if(use[x+1]==0&&use[x]==i){use[x+1]=i;sum++;}
    return sum;
}
int main()
{
    int n,m,d;
    int i,j=0,sum=0;
    scanf("%d%d",&n,&m);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i][0]);
        a[i][1]=i+1;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    use[0]=-1;
    use[n+1]=-1;
    for(i=1; i<=m; i++)
    {
        scanf("%d",&d);
        sum=0;
        while(d<a[j][0]&&j<n)
        {
            sum+=del(a[j][1],i);
            j++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
