#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,W;
    int i,j;
    int vitem[1005],witem[1005];
    int data[1005][1005]={0};
    scanf("%d%d",&n,&W);
    for(i=1;i<=n;i++) scanf("%d%d",&witem[i],&vitem[i]);
    for(i=1;i<=n;i++) //item���ǹ͹ (i�����)
    {
        for(j=1;j<=W;j++) //W(��ҹ��˹ѧ���������Ѻ��) �����1...W���ǵ�� (j��觴������)
        {
            if(i==0||j==0) data[i][j]=0;
            else if(witem[i]>j) data[i][j]=data[i-1][j];
            else if(data[i-1][j]>vitem[i]+data[i-1][j-witem[i]])
                    data[i][j]=data[i-1][j];
            else data[i][j]=vitem[i]+data[i-1][j-witem[i]];
        }
    }
//    for(i=1;i<=n;i++)
//    {
//        for(j=1;j<=W;j++) printf("%d ",data[i][j]);
//        printf("\n");
//    }
    printf("%d",data[n][W]);
    return 0;
}
