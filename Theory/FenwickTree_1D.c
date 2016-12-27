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
int freqAt(int *tree,int idx)
{
    int sum = tree[idx];
    int z,y;
    y=idx-1;
    z=idx-(idx&-idx);
    while(y>z)
    {
        sum-=tree[y];
        y-=(y&-y);
    }
    return sum;
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
void createfwt(int *tree,int n)
{
    int x,sum=0,idx,y,z;
    for(idx=1; idx<=n; idx++)
    {
        sum=tree[idx];
        y=idx-1;//y=ตัวที่ index-1
        z=idx-(idx&-idx);//ตัวที่ indexชี้
        while(y>z)
        {
            sum+=tree[y];
            y-=(y&-y);
        }
        tree[idx]=sum;
    }
}
int main()
{
    int tree[18]= {0,1,0,2,1,1,3,0,4,2,5,2,2,3,1,0,2};//กล่องเริ่มที่ 1 ถึง n 0 เอาไว้หยุด
    int i;
    createfwt(tree, 17);

    return 0;
}
