#include <stdio.h>

using namespace std;

int chk[60050]={0};
int main()
{
    int n,a,b;
    scanf("%d",&n);
    chk[30000]=-1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        for(int j=0;j<=60000;j++)
        {
            if(chk[j]<i&&chk[j]!=0) continue;
            b=(j-a)%60001;
            if(b<0) b+=60001;
            if(chk[b]<i&&chk[b]!=0) chk[j]=i;
        }
    }
    for(int j=60000;j>=0;j--)
        if(chk[j]!=0) {printf("%d",j-30000);break;}
    return 0;
}
