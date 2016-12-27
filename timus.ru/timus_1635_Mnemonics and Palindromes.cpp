#include <stdio.h>
#include <string.h>
#define INF 1000000000
using namespace std;

char a[4050];
int len;
int f[4050]={0},p[4050]={0};
bool map[4050][4050];
int print(int n)
{
    if(n==0) return 0;
    print(p[n]);
    for(int i=p[n]+1;i<=n;i++) printf("%c",a[i]);
    printf(" ");
}
int main()
{
    gets(&a[1]);
    len=strlen(&a[1]);
    for(int i=1;i<=len;i++) map[i][i]=true;
    for(int j=2;j<=len;j++)
    {
        if(a[j-1]==a[j]) map[j-1][j]=true;
        for(int i=j-2;i>=1;i--)
        {
            if(a[i]==a[j]&&map[i+1][j-1]==true) map[i][j]=true;
        }
    }
    for(int j=1;j<=len;j++)
    {
        int min=INF;
        for(int i=1;i<=j;i++)
        {
            if(map[i][j]==true&&f[i-1]+1<min)
            {
                min=f[i-1]+1;
                p[j]=i-1;
            }
        }
        f[j]=min;
    }
    printf("%d\n",f[len]);
    print(len);
    return 0;
}
