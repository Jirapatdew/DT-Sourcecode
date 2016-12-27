#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[0]<bb[0]) return 1;
    else if(aa[0]==bb[0]&&((aa[1]-aa[2])<(bb[1]-bb[2]))) return 1;
    else if(aa[0]==bb[0]&&((aa[1]-aa[2])==(bb[1]-bb[2]))&&aa[1]<bb[1]) return 1;
    else return -1;
}
int main()
{
    int i,j,sum;
    int team[4][4]={0};
    char data[4][25]={'\0'};
    int sc[5][5]={0};
    for(i=0;i<4;i++)    scanf("%s",&data[i]);
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)    scanf("%d",&sc[i][j]);
    for(i=0;i<4;i++)    team[i][3]=i;//·ÕÁ·Õè
    for(i=0;i<4;i++)//·Ó»ÃÐµÙ
    {
        sum=0;
        for(j=0;j<4;j++) sum+=sc[i][j];
        team[i][1]=sum;
    }
    for(i=0;i<4;i++)//â´¹ÂÔ§
    {
        sum=0;
        for(j=0;j<4;j++) sum+=sc[j][i];
        team[i][2]=sum;
    }
    for(i=0;i<4;i++)
    {
        for(j=i+1;j<4;j++)
        {
            if(sc[i][j]>sc[j][i]) {team[i][0]+=3;}
            else if(sc[i][j]==sc[j][i]){team[i][0]++;team[j][0]++;}
            else team[j][0]+=3;
        }
    }
    qsort(team,4,sizeof(team[0]),cmp);
    for(i=0;i<4;i++)
    {
        printf("%s ",data[team[i][3]]);
        printf("%d\n",team[i][0]);
    }
    return 0;
}
