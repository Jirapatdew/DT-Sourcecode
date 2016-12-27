#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define MIN(a,b) (a<b)?a:b
using namespace std;
int data[15]={0};
int con[60][4]={0};
int perm[15]={0};
int n,m,total=0;
bool chk()
{
    int st[2],cnt=0,sum,path;
    for(int i=1;i<=m;i++)
    {
        cnt=sum=0;
        for(int j=1;j<=n&&cnt<2;j++)
        {
            if(perm[j]==con[i][0]||perm[j]==con[i][1]) st[cnt++]=j;
            else if(cnt==1) sum+=data[j];
        }
        path=MIN(sum,total-sum-data[st[0]]-data[st[1]]);
        if(con[i][2]==1&&path>con[i][3]) return false;
        if(con[i][2]==2&&path<con[i][3]) return false;
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {scanf("%d",&data[i]);total+=data[i];}
    for(int i=1;i<=m;i++) scanf("%d%d%d%d",&con[i][0],&con[i][1],&con[i][2],&con[i][3]);
    for(int i=1;i<=n;i++) perm[i]=i;
    while(perm[1]==1)
    {
        if(chk()) {printf("yes");return 0;}
        next_permutation(&perm[1],&perm[n+1]);
    }
    printf("no");
    return 0;
}
