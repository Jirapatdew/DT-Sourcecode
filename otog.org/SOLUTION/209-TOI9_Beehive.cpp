/*
TASK: beehive.cpp
LANG: C++
COMPILER: WCB
AUTHOR: Jirapat Atiwattanachai
ID: KKU07
*/
#include <stdio.h>
#define MAX(a,b) ((a>b)?a:b)

using namespace std;

int Map[1050][1050]={0};
int Num[1050][1050]={0};
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) scanf("%d",&Map[i][j]);
    for(int j=0;j<m;j++) Num[0][j]=1;
    for(int i=1;i<n;i++)
    {
        if(i%2==0)
        {
            Num[i][0]+=Num[i-1][0];
            Map[i][0]+=Map[i-1][0];
            for(int j=1;j<m;j++)
            {
                if(Map[i-1][j-1]==Map[i-1][j])
                {
                    Num[i][j]+=Num[i-1][j-1]+Num[i-1][j];
                    Map[i][j]+=Map[i-1][j-1];
                }
                else if(Map[i-1][j-1]>Map[i-1][j])
                {
                    Map[i][j]+=Map[i-1][j-1];
                    Num[i][j]+=Num[i-1][j-1];
                }
                else
                {
                    Map[i][j]+=Map[i-1][j];
                    Num[i][j]+=Num[i-1][j];
                }
            }
        }
        else
        {
            for(int j=0;j<m-1;j++)
            {
                if(Map[i-1][j]==Map[i-1][j+1])
                {
                    Num[i][j]+=Num[i-1][j]+Num[i-1][j+1];
                    Map[i][j]+=Map[i-1][j];
                }
                else if(Map[i-1][j]>Map[i-1][j+1])
                {
                    Map[i][j]+=Map[i-1][j];
                    Num[i][j]+=Num[i-1][j];
                }
                else
                {
                    Map[i][j]+=Map[i-1][j+1];
                    Num[i][j]+=Num[i-1][j+1];
                }
            }
            Num[i][m-1]+=Num[i-1][m-1];
            Map[i][m-1]+=Map[i-1][m-1];
        }
    }
    int mx=0,sum=0;
    for(int j=0;j<m;j++) mx=MAX(mx,Map[n-1][j]);
    for(int j=0;j<m;j++) if(Map[n-1][j]==mx) sum+=Num[n-1][j];
    printf("%d %d",mx,sum);
    return 0;
}
