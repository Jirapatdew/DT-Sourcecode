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
    int n,m,a,b,c,d,e,i,tree[200001]={0};
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&a);
        if(a==1)
        {
            scanf("%d%d",&b,&c);//ฝังแร่bในc
            update(tree,c,b,n);
        }
        else
        {
            scanf("%d%d",&d,&e);//มูลค่าของที่ดินแปลงย่อยจากแปลงที่ D ไปจนถึงแปลงที่ E
            printf("%d\n",freqTo(tree,e)-freqTo(tree,d-1));
        }
    }
    return 0;
}
