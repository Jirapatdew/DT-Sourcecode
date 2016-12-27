#include <stdio.h>
#include <stdlib.h>

int data[1005]={0};
int chk[1005]={0};
int ans[1005]={0};
int n,p=0;

int per(int a)
{
    int i;
    if(a<=n&&p<=1)
    {
        for(i=(p==1)?1:data[a];i<=n;i++)
        {
            if(chk[i]==0)
            {
                chk[i]=1;
                ans[a]=i;
                per(a+1);
                chk[i]=0;
            }
        }
    }
    else
    {
        if(p==1)
        {
            for(i=1;i<=n;i++) printf("%d\n",ans[i]);
        }
        p++;
    }
}
int main()
{

    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&data[i]);
    per(1);
    return 0;
}
