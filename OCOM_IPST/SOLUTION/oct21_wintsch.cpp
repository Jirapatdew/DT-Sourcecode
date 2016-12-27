#include <stdio.h>
#define MIN(_x,_y) (((_x)<(_y))?(_x):(_y))
using namespace std;

int s[1010]={0},t[1010]={0},w[1010]={0};
int a[1010][2]={0},sz=0;//0=w all 1=subject
int p[1010]={0};
int print(int u,int num)
{
    if(u==0)
    {
        printf("%d\n",num);
        return 0;
    }
    print(p[u],num+1);
    printf("%d ",u);
}
int main()
{
    int n,id;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d%d%d",&s[i],&t[i],&w[i]);t[i]--;}
    s[0]=-1u/2;
    a[0][0]=a[0][1]=0;
    sz++;
    for(int i=n;i>0;i--)
    {
        id=0;
        for(int j=1;j<sz;j++)
        {
            if(t[i]<s[a[j][1]]&&a[id][0]<a[j][0]) id=j;
        }
        a[sz][0]=a[id][0]+w[i];
        a[sz][1]=i;
        p[i]=a[id][1];
        sz++;
    }
    id=0;
    for(int i=1;i<sz;i++)
    {
        if(a[id][0]<a[i][0]) id=i;
    }
    printf("%d\n",a[id][0]);
    print(a[id][1],0);
    return 0;
}
