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
    for(i=0;i<lenA;i++) table[i][0]=0;//ให้stringAเป็นแกนตั้ง( ให้iวิ่งแถว )
    for(j=0;j<lenB;j++) table[0][j]=0;//stringBเป็นแกนนอน( ให้jวิ่งคอลัมภ์)
    for(i=1;i<=lenA;i++)
    {
        for(j=1;j<=lenB;j++)//tableเริ่มจาก 1,1 แต่stringเวลารับมาเริ่มจาก 0
        {
            if(stringA[i-1]==stringB[j-1]) table[i][j]=table[i-1][j-1]+1;
            else table[i][j]=0;
            if(max<table[i][j]) {max=table[i][j];x=i;y=j;}
        }
    }
    i=x;j=y;
    d=table[x][y];
    while(i>0&&j>0)//ไล่กลับเพื่อดูว่าตัวไหนเท่าบ้าง
    {
        ans[--d]=stringB[j-1];i--;j--;
    }
    printf("%s",ans);
    return 0;
}
