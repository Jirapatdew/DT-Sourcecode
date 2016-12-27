#include <stdio.h>
#include <algorithm>
#define MAX(a,b) (a>b)?a:b
#define INF 1000000000

using namespace std;


char data[100050];
int f[5][5][5][5]={0};
int tmp[5][5][5][5]={0};
int chk(char a)
{
    if(a=='B') return 1;
    else if(a=='F') return 2;
    else return 3;
}
int cal(int a,int b,int c)
{
    if(a==0&&b==0) return 1;
    if(a==0&&b==c) return 1;
    if(a==0&&b!=c) return 2;
    if(a==b&&a==c) return 1;
    else if(a!=b&&a!=c&&b!=c) return 3;
    else return 2;
}
int main()
{

    int n,x;
    scanf("%d",&n);
    scanf("%s",data+1);
    x=chk(data[1]);
    f[0][x][0][0]++;
    f[0][0][0][x]++;
    for(int i=2;i<=n;i++)
    {
        x=chk(data[i]);
        for(int a=0;a<4;a++)
            for(int b=0;b<4;b++)
                for(int c=0;c<4;c++)
                    for(int d=0;d<4;d++) {tmp[a][b][c][d]=0;}

        for(int a=0;a<4;a++)
            for(int b=0;b<4;b++)
                for(int c=0;c<4;c++)
                    for(int d=0;d<4;d++)
                        if(f[a][b][c][d]!=0)
                        {
                            tmp[b][x][c][d]=MAX(tmp[b][x][c][d],f[a][b][c][d]+cal(a,b,x));
                            tmp[a][b][d][x]=MAX(tmp[a][b][d][x],f[a][b][c][d]+cal(c,d,x));
                        }

        for(int a=0;a<4;a++)
            for(int b=0;b<4;b++)
                for(int c=0;c<4;c++)
                    for(int d=0;d<4;d++) f[a][b][c][d]=tmp[a][b][c][d];

    }
    int mx=0;
    for(int a=0;a<4;a++)
        for(int b=0;b<4;b++)
            for(int c=0;c<4;c++)
                for(int d=0;d<4;d++) mx=MAX(mx,f[a][b][c][d]);
    printf("%d",mx);
    return 0;
}
