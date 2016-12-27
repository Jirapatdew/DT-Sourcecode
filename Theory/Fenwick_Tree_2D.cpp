#include <stdio.h>

using namespace std;

int Max_x,Max_y;
int T[501][501]={0};
int update(int x,int y,int v)
{
    for(int i=x;i<=Max_x;i+=(i&-i))
        for(int j=y;j<=Max_y;j+=(j&-j)) T[i][j]+=v;
}
int freqTo(int x,int y)
{
    int sum=0;
    for(int i=x;i>0;i-=(i&-i))
        for(int j=y;j>0;j-=(j&-j)) sum+=T[i][j];
    return sum;
}
int freqAt(int x,int y)
{
    return freqTo(x,y)-freqTo(x-1,y)-freqTo(x,y-1)+freqTo(x-1,y-1);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    Max_x=n;
    Max_y=m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) update(i,j,i+j);
    printf("%d\n",freqAt(21,32));
    return 0;
}
