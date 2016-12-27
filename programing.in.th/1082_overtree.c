#include <stdio.h>
#include <stdlib.h>

int p[100005]={0};
int h[100005]={0};
int data[1000005][3]={0};
int cmp(const void*a,const void*b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[2]>bb[2]) return 1;
    else return -1;
}
void unionset(int s,int t)
{
    if(h[s]>h[t]) p[t]=s;
    else
    {
        p[s]=t;
        if(h[s]==h[t]) h[t]++;//ถ้าสูงเท่าให้เพิ่มความสูงอีก
    }
}
int findset(int e)
{
    while(p[e]!=e)
    {
        p[e]=p[p[e]];
        e=p[e];
    }
    return e;
}
int main()
{
    int n,m,i,num,dt;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++) scanf("%d%d%d",&data[i][0],&data[i][1],&data[i][2]);
    qsort(data,m,sizeof(data[0]),cmp);//เรียงตามระยะทาง
    for(i=1;i<=n;i++) p[i]=i;//ให้มันเป็นพ่อตัวเอง
    num=1;dt=0;
    while(num<n)//num=จำนวนเส้นที่ถูกเลือก
    {
        p[data[dt][0]]=findset(data[dt][0]);
        p[data[dt][1]]=findset(data[dt][1]);
        if(p[data[dt][0]]!=p[data[dt][1]])
        {
            printf("%d %d\n",data[dt][0],data[dt][1]);
            num++;
            unionset(p[data[dt][0]],p[data[dt][1]]);
        }
        dt++;
    }

    return 0;
}
