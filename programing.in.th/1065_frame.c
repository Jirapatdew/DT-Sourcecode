#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int min(int a,int b)
{
    if(a<b) return a;
    else return b;
}
int main()//ใช้หลักการที่ว่า ถ้าทับซ้อนกันจะมีพื้นที่หายไปซึ้งส่งผลต่อค่า x,y
{
    int n,m,dt;
    int i,j,k,total=0,p;
    int x[1005][2]={0},y[1005][2]={0};
    int a[2]={0},b[2]={0};
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++) scanf("%d%d%d%d",&x[i][0],&y[i][0],&x[i][1],&y[i][1]);
    for(i=0;i<m;i++)
    {
        total=0;
        scanf("%d%d%d%d",&a[0],&b[0],&a[1],&b[1]);
        for(j=0;j<n;j++)
        {
            p=0;
            dt=max(x[j][1],a[1])-min(x[j][0],a[0]);
            if(dt<(x[j][1]-x[j][0])+(a[1]-a[0])) p++;
            dt=max(y[j][0],b[0])-min(y[j][1],b[1]);
            if(dt<(y[j][0]-y[j][1])+(b[0]-b[1])) p++;
            if(p==2) total++;//ถ้าทั้งสองด้านลดแสดงว่ามีส่วนทับกัน
        }
        printf("%d\n",total);
    }
    return 0;
}
