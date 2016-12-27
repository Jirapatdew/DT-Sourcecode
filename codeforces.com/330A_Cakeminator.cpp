#include <stdio.h>

using namespace std;

int main()
{
    int n,m,num=0;
    char a[100];
    int r[100]={0},c[100]={0};
    scanf("%d%d\n",&n,&m);
    for(int i=0;i<n;i++)
    {
        gets(a);
        for(int j=0;j<m;j++)
        {
            if(a[j]=='S') {r[i]=1;c[j]=1;}
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) if(r[i]==0||c[j]==0) num++;
    printf("%d",num);
    return 0;
}