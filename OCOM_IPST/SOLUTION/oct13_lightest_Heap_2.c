#include <stdio.h>
#include <stdlib.h>

int A[100005]={0},B[100005]={0},size=0;
int swap(int x[],int a,int b)
{
    int tmp;
    tmp=x[a];
    x[a]=x[b];
    x[b]=tmp;
    return 0;
}
int heapify(int x) //x is node that visit
{
    int smallest=x,tmp;
    int left=x*2,right=x*2+1;
    if(left<=size&&A[smallest]>A[left]) smallest=left;
    if(right<=size&&A[smallest]>A[right]) smallest=right;
    if(smallest!=x)
    {
        swap(A,x,smallest);
        swap(B,x,smallest);
        heapify(smallest);
    }
}

int Insert(int a,int b)// a is val
{
    int p,e,tmp;
    size++;
    A[size]=a;
    B[size]=b;
    p=size/2;
    e=size;
    while(e>1)
    {
        if(A[p]>A[e])
        {
            swap(A,p,e);
            swap(B,p,e);
            e=p;
            p=e/2;
        }
        else break;
    }
    return 0;
}
int ExtractMin()
{
    if(size==0) {printf("0\n");return 0;}
    printf("%d\n",B[1]);
    A[1]=A[size];
    B[1]=B[size--];
    heapify(1);
    return 0;
}
int main()
{
    int n,m;
    int i,w,v;
    char c[5];
    scanf("%d%d\n",&n,&m);
    for(i=0;i<n+m;i++)
    {
        scanf("%s",c);
        if(c[0]=='T')
        {
            scanf("%d%d",&w,&v);
            Insert(w,v);
        }
        else ExtractMin();
    }
    return 0;
}
//ใช้ได้ทั้ง 2 แบบ
