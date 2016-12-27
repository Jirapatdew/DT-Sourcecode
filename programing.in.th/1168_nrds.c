#include <stdio.h>
#include <stdlib.h>

int data[550]= {0},p=0;
int chk[12]= {0};
int cmp(const void*a,const void*b)
{
    int aa=*(int*)a;
    int bb=*(int*)b;
    if(aa>bb) return 1;
    else return -1;
}
int ten(int x)
{
    int i,num=1;
    for(i=0; i<x; i++) num*=10;
    return num;
}
int bi(int a)
{
    int i,b=0;
    if(a>9)
    {
        for(i=9; i>0; i--)
        {
            if(chk[i]==1) data[p]+=i*ten(b++);
        }
        p++;
        return 0;
    }
    for(i=0; i<2; i++)
    {
        chk[a]=i;
        bi(a+1);
    }
}
int main()
{
    int n;
    int i,k;
    int a;
    scanf("%d",&n);
    bi(1);
    qsort(data,512,sizeof(int),cmp);
    for(; n>0; n--)
    {
        scanf("%d",&a);
        if(a>511) printf("-1\n");
        else printf("%d\n",data[a]);
    }
    return 0;
}
