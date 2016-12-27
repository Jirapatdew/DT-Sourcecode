#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char a[200010]={0};
int sum[200010]={0};
int main()
{
    scanf("%s",a);
    int len=strlen(a),num=1;
    sum[0]=1;
    for(int i=1;i<len;i++) sum[i]=(a[i]==a[i-1])?sum[i-1]+1:1;
    if(len>=2)printf("%c%c",a[0],a[1]);
    else printf("%c",a[0]);
    for(int i=2;i<len;i++)
    {
        if(sum[i]==2&&sum[i-2]==2) {sum[i]=1;continue;}
        if(sum[i]>2) {sum[i]=sum[i-1];continue;}
        printf("%c",a[i]);
    }
    return 0;
}