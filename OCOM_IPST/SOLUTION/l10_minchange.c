#include <stdio.h>
#include <stdlib.h>

//dynamic หา ตัวที่สามารถนำ a and b มารวมกันจนเท่ากับมัน
//คล้ายข้อ nugget number
int main()
{
    int data[10105]={0};
    int a,b,n;
    int i,m,dt;
    scanf("%d%d%d",&a,&b,&n);
    data[a]=a;
    data[b]=b;
    for(i=1;i<=10105;i++)
    {
        if(a<i&&data[i-a]!=0) data[i]=i;
        if(b<i&&data[i-b]!=0) data[i]=i;
    }
    dt=0;
    for(i=10105;i>=1;i--)
    {
        if(data[i]!=0) dt=data[i];
        else data[i]=dt;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        printf("%d\n",data[m]);
    }
    return 0;
}
