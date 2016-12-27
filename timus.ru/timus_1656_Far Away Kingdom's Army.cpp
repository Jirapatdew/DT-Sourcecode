#include <stdio.h>
using namespace std;

int Q[1050][2]={0};
int be=0,end=0;
void enqueue(int a,int b)
{
    Q[end][0]=a;
    Q[end++][1]=b;
}
void dequeue()
{
    be++;
}
int main()
{
    int n,p=0;
    int data[40]={0};
    int map[15][15]={0};
    int a,b;
    scanf("%d",&n);
    for(int i=n*n;i>0;i--)
    {
        scanf("%d",&a);
        data[a-170]++;
    }
    enqueue(1,1);
    enqueue(1,n);
    enqueue(n,1);
    enqueue(n,n);
    while(be!=end)
    {
        a=Q[be][0];
        b=Q[be][1];
        dequeue();
        if(a<1||a>n||b<1||b>n||map[a][b]!=0) continue;
        while(data[p]==0) p++;
        map[a][b]=p+170;
        data[p]--;
        enqueue(a+1,b);
        enqueue(a,b+1);
        enqueue(a-1,b);
        enqueue(a,b-1);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) printf("%d ",map[i][j]);
        printf("\n");
    }
    return 0;
}
