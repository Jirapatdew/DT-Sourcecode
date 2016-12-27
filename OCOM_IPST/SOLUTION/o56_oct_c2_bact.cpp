#include <stdio.h>
#include <stdlib.h>
#define MIN(_x,_y) (((_x)<(_y))?(_x):(_y))
#define MAX(_x,_y) (((_x)>(_y))?(_x):(_y))

using namespace std;

int Map[35][35]={0};
int chk[901]={0};
int L,W,M;
int div(int a)
{
    if(a>MAX(L,W))
    {

    }
    else
    {

    }
}
int main()
{
    scanf("%d%d%d",&L,&W,&M);
    for(int i=1;i<=L;i++)
        for(int j=1;j<=W;j++) scanf("%d",&Map[i][j]);

    return 0;
}
