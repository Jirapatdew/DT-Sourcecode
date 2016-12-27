/*
TASK: spaceship.cpp
LANG: C++
COMPILER: WCB
AUTHOR: Jirapat Atiwattanachai
ID: KKU07
*/
#include <stdio.h>
#include <algorithm>
#define INF 2000000000
#define MIN(_a,_b) ((_a<_b)?_a:_b)
using namespace std;

int main()
{
    int n,m;
    int x[15]={0},y[15]={0},z[15]={0};
    int M[15]={0},K[15]={0},C[15]={0};
    scanf("%d",&n);
    scanf("%d%d%d",&x[0],&y[0],&z[0]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
        scanf("%d%d%d",&M[i],&K[i],&C[i]);
    }
    int perm[15]={0};
    for(int i=0;i<m;i++) perm[i]=i+1;
    int mn=INF;
    do
    {
        //for(int i=0;i<m;i++) printf("%d ",perm[i]);
        //printf("\n");
        int sum=INF;
        int a=0,b=0,c=0;
        for(int i=0;i<m;i++)
        {
            if(i==0) sum=(x[perm[i]]-x[0])*(x[perm[i]]-x[0])+(y[perm[i]]-y[0])*(y[perm[i]]-y[0])+(z[perm[i]]-z[0])*(z[perm[i]]-z[0]);
            else sum+=(x[perm[i]]-x[perm[i-1]])*(x[perm[i]]-x[perm[i-1]])+(y[perm[i]]-y[perm[i-1]])*(y[perm[i]]-y[perm[i-1]])+(z[perm[i]]-z[perm[i-1]])*(z[perm[i]]-z[perm[i-1]]);
            a+=M[perm[i]];
            b+=K[perm[i]];
            c+=C[perm[i]];
            if(a>=n&&b>=n&&c>=n) break;
        }
        mn=MIN(mn,sum);
    }while(next_permutation(perm,perm+m));
    printf("%d",mn);
    return 0;
}
