#include <stdio.h>
#include <stdlib.h>

int data[11][2]={0},ans=1000000;
int chk[11]={0};
int n;
int t=0;
int temp;
void perket(int s,int b)
{
    int a;
    if(s-b<0) temp=b-s;
    else temp=s-b;
    if(temp<ans&&t!=0) ans=temp;
    t=1;
    for(a=0;a<n;a++)
    {
        if(chk[a]==0)
        {
            chk[a]=1;
            perket(s*data[a][0],b+data[a][1]);
            chk[a]=0;
        }
    }
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d%d",&data[i][0],&data[i][1]);
    perket(1,0);
    printf("%d",ans);
    return 0;
}

