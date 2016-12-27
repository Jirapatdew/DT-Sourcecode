#include <stdio.h>
#include <string.h>
using namespace std;

int n,cnt=0;
char ans[30]={'\0'};
char mem[20000][30]={'\0'};
int gen(int op,int cl)
{
    int a=op+cl;
    if(op<n||cl<n)
    {
        if(op<n) {ans[a]='(';gen(op+1,cl);}
        if(cl<n&&cl<op) {ans[a]=')';gen(op,cl+1);}
    }
    else
    {
        strcpy(mem[cnt++],ans);
    }
}
int main()
{
    scanf("%d",&n);
    gen(0,0);
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++) printf("%s\n",mem[i]);
    return 0;
}
