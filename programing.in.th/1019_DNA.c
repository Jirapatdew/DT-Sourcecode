#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char stringA[201];
    char stringB[201];
    char ans[201]={'\0'};
    int table[202][202];
    int i,j,lenA,lenB,d=0;
    int max=0,x=0,y=0;
    scanf("%s%s",stringA,stringB);
    lenA=strlen(stringA);
    lenB=strlen(stringB);
    for(i=0;i<lenA;i++) table[i][0]=0;//���stringA��᡹���( ���i����� )
    for(j=0;j<lenB;j++) table[0][j]=0;//stringB��᡹�͹( ���j��觤������)
    for(i=1;i<=lenA;i++)
    {
        for(j=1;j<=lenB;j++)//table������ҡ 1,1 ��string�����Ѻ��������ҡ 0
        {
            if(stringA[i-1]==stringB[j-1]) table[i][j]=table[i-1][j-1]+1;
            else table[i][j]=0;
            if(max<table[i][j]) {max=table[i][j];x=i;y=j;}
        }
    }
    i=x;j=y;
    d=table[x][y];
    while(i>0&&j>0)//����Ѻ���ʹ���ҵ���˹��Һ�ҧ
    {
        ans[--d]=stringB[j-1];i--;j--;
    }
    printf("%s",ans);
    return 0;
}
