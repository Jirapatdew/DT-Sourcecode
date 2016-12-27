#include <stdio.h>
#include <stdlib.h>


void update(int *tree,int idx ,int val,int MaxVal)
{
    while (idx <= MaxVal)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
int freqTo(int *tree,int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(idx&-idx);
    }
    return sum;
}
int main()
{
    int n,m,a,b,c,d,e,i,tree[200001]={0},x;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&a);
        if(a==1)
        {
            scanf("%d%d%d",&b,&c,&d);//มีการฉายรังสีจากช่อง B ไปยังช่อง C ด้วยพลัง D หน่วย
            update(tree,b,d,n);
            update(tree,c+1,-d,n);
        }
        else
        {
            scanf("%d",&e);//ตอบมูลค่าของที่ดินย่อยที่ E ในขณะนั้น
            printf("%d\n",freqTo(tree,e));
        }
    }
    return 0;
}
