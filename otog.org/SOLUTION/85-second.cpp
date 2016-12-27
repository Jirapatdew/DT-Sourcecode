#include <stdio.h>
#include <stdlib.h>
#define MAX_n 50

using namespace std;

int n,ans[MAX_n]={0},p=0,cnt=0;
void print()
{
    int mx=0;
   // for(int i=0;i<p;i++) printf("%d ",ans[i]);
   // printf("\n");
    cnt++;
    mx=ans[p-1];
    for(int k=mx;k>=1;k--)
    {
        for(int i=0;i<p;i++)
        {
            if(ans[i]-k>=0) printf("#");
            else printf(".");
        }
        printf("\n");
    }
    printf("=\n");
}
int build(int a,int mx)
{
    //if(a<0||a<=mx) return 0;
    if(a==0) print();
    else
    {
        for(int i=mx+1;i<=n;i++)
        {
            if(a>=i)
            {
                ans[p++]=i;
                build(a-i,i);
                p--;
            }
            else return 0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    build(n,0);
    //printf("%d\n",cnt);
    return 0;
}
