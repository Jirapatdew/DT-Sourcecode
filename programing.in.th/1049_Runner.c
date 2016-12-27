#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[2]>bb[2]) return 1;
    else if(aa[2]==bb[2]&&aa[1]<bb[1]) return 1;
    else if(aa[2]==bb[2]&&aa[1]==bb[1]&&aa[3]>bb[3]) return 1;
    else return -1;
}
int main()
{
    int n,m,a,x;
    int i;
    int data[100005][4]={0};
    int line[10005]={0};
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&data[i][0],&a,&data[i][1]);//1= ความเร็ว  0=หมายเลขประจำตัว
        line[a]++;
        data[i][2]=line[a];//2 = อยู่คนที่เท่าไหร่ใน ลู่a
        data[i][3]=a;
    }
    qsort(data,n,sizeof(data[0]),cmp);
    x=data[0][2];
    printf("%d\n",data[0][0]);
    for(i=1;i<n;i++)
    {
        if(x!=data[i][2]) {x=data[i][2];printf("%d\n",data[i][0]);}
    }
    return 0;
}
