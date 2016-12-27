#include <stdio.h>
#include <stdlib.h>

int data[1005]={0};
int chk[1005]={0};
int ans[1005]={0};
int n,p=0;


int print(int i)
{
    if(i>n) return 0;
    printf("%d\n",ans[i]);
    print(i+1);
}
int scan(int i)
{
    if(i>n) return 0;
    scanf("%d",&data[i]);
    scan(i+1);
}
int loop_chk(int i,int a)
{
    if(i>n) return 0;
    if(chk[i]==0)
    {
        chk[i]=1;
        ans[a]=i;
        per(a+1);
        chk[i]=0;
    }
    loop_chk(i+1,a);
}
int per(int a)
{
    int i;
    if(a<=n&&p<=1)
    {
        if(p==1) loop_chk(1,a);
        else loop_chk(data[a],a);
    }
    else
    {
        if(p==1) print(1);
        p++;
    }
}
int main()
{
    int i;
    scanf("%d",&n);
    scan(1);
    per(1);
    return 0;
}
