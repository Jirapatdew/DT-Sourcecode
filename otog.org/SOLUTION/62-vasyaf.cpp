#include <stdio.h>
using namespace std;
int data[15][85]={0};
int main()
{
    int s;
    scanf("%d",&s);
    for(int i=0;i<=9;i++) data[1][i]=1;
    for(int i=2;i<=9;i++)
        for(int j=0;j<=s;j++)
            for(int k=0;k<=9&&j-k>=0;k++)
                data[i][j]+=data[i-1][j-k];
    if(s==1) printf("%d",data[9][s]+1);
    else printf("%d",data[9][s]);
    return 0;
}
