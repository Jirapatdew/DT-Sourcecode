#include <stdio.h>
#include <stdlib.h>

//t=ทิศของตัวที่ >1  0=ขวา 1=ซ้าย
int n,p,t;
int address(int a)
{
    if(t==1)
    {
        if(p-a+1>=0) return p-a+1;
        else return n-a+1+p;
    }
    else
    {
        if(p+a-1<n) return p+a-1;
        else return a-n-1+p;
    }
}
int main()
{
    int m,x,y,k,tmp,i;
    char ch;
    int data[500005]={0};
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++) scanf("%d",&data[i]);
    p=0;
    t=0;
    for(i=0;i<m;i++)
    {
        scanf("%c",&ch);
        if(ch=='\n') scanf("%c",&ch);
        if(ch=='a')
        {
            scanf("%d",&x);
            scanf("%d",&y);
            x=address(x);
            y=address(y);
            tmp=data[x];
            data[x]=data[y];
            data[y]=tmp;
        }
        else if(ch=='b')
        {
            scanf("%d",&x);
            scanf("%d",&k);
            data[address(x)]=k;
        }
        else if(ch=='c')
        {
            scanf("%d",&x);
            p=address(x);
            t=1-t;
        }
        else if(ch=='q')
        {
            scanf("%d",&x);
            printf("%d\n",data[address(x)]);
        }
    }
    return 0;
}
