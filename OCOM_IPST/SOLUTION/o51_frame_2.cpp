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
    int sum,path;
    int qsum[15]={0};
    int idx[15]={0};
    for(int i=1;i<=n;i++) {qsum[i]=qsum[i-1]+data[i];idx[perm[i]]=i;}
    for(int i=1;i<=m;i++)
    {
        sum=0;
        if(idx[con[i][0]]>idx[con[i][1]]) sum=qsum[idx[con[i][0]]-1]-qsum[idx[con[i][1]]];
        else sum=qsum[idx[con[i][1]]-1]-qsum[idx[con[i][0]]];
        path=MIN(sum,total-sum-data[idx[con[i][0]]]-data[idx[con[i][1]]]);
        if(con[i][2]==1&&path>con[i][3]) return false;
        if(con[i][2]==2&&path<con[i][3]) return false;
    }
    return true;
}
int main()
{
    int fac=1;
    scanf("%d%d",&n,&m);
    for(int i=2;i<n;i++) fac*=i;
    for(int i=1;i<=n;i++) {scanf("%d",&data[i]);total+=data[i];}
    for(int i=1;i<=m;i++) scanf("%d%d%d%d",&con[i][0],&con[i][1],&con[i][2],&con[i][3]);
    for(int i=1;i<=n;i++) perm[i]=i;
    //for(int i=1;i<=fac;i++)
    do
    {
        if(chk()) {printf("yes");return 0;}
        //for(int i=1;i<=n;i++) printf("%d ",perm[i]);
        //printf("\n");

    }while(next_permutation(&perm[2],&perm[n+1]));
    printf("no");
    return 0;
}
