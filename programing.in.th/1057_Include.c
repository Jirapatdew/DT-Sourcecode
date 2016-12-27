#include <stdio.h>
#include <stdlib.h>

int chk[1005]={0};//ถ้าโดนเรียกแล้วจะเท่ากับ st
int Truth_value[1005]={0};//1=true -1=false
int data[1005][20]={0};
int check(int a,int st)
{
    int i;

    if(Truth_value[st]!=0) return 0;//รู้คำตอบแล้ว
    if(chk[a]==st||Truth_value[a]==-1) {Truth_value[st]=-1;return 0;}
    //else if(Truth_value[a]==1) return 0; *****bug รับประกันไม่ได้ว่าจะไม่เกิดกรณีเรียนซ้ำ 2 รอบ
    chk[a]=st;
    for(i=1;i<=data[a][0];i++)
    {
        check(data[a][i],st);
    }
}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&data[i][0]);
        for(j=1;j<=data[i][0];j++)
        {
            scanf("%d",&data[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        check(i,i);
        if(Truth_value[i]==0) Truth_value[i]=1;
    }

    for(i=1;i<=n;i++)
    {
        if(Truth_value[i]==-1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
