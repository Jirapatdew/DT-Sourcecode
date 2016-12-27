#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[0]>bb[0]) return 1;
    else return -1;
}
int main()
{
    int data[100005][3]={0};
    int n,i,j,total=0;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d%d%d",&data[i][0],&data[i][1],&data[i][2]);
    qsort(data,n,sizeof(data[0]),cmp);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(data[i][0]+20<data[j][0]) break;
            if((data[i][0]-data[j][0])*(data[i][0]-data[j][0])+(data[i][1]-data[j][1])*(data[i][1]-data[j][1]) < (data[i][2] + data[j][2])*(data[i][2] + data[j][2])) total++;
        }
    }
    printf("%d",total);
    return 0;
}
