#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char stringA[101];
    char stringB[101];
    char ans[101]={'\0'};
    int table[101][101];
    int i,j,lenA,lenB,d=0;
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
            else if(table[i][j-1]>=table[i-1][j]) table[i][j]=table[i][j-1];
            else table[i][j]=table[i-1][j];
        }
    }
    i=lenA;j=lenB;
    d=table[lenA][lenB];
    while(i>0&&j>0)//����Ѻ���ʹ���ҵ���˹��Һ�ҧ
    {
        if(stringA[i-1]==stringB[j-1]) {ans[--d]=stringB[j-1];i--;j--;}
        else if(table[i][j-1]>=table[i-1][j]) j--;
        else i--;
    }
    printf("%s",ans);
    return 0;
}
