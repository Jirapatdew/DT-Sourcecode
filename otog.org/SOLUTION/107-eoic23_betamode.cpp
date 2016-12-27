#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int f[10050]={0};
int tm[10050]={0};
int main()
{
    char a[10050],b[10050];
    int len_a,len_b;
    int mx=0,idx=0;
    scanf("%s%s",&a[1],&b[1]);
    len_a=strlen(&a[1]);
    len_b=strlen(&b[1]);
    for(int j=1;j<=len_b;j++)
    {
        for(int i=1;i<=len_a;i++)
        {
            tm[i]=0;
            if(a[i]==b[j])
                tm[i]=f[i-1]+1;
            if(mx<tm[i]) {mx=tm[i];idx=i;}
            else if(mx==tm[i]&&i<idx) idx=i;
        }
        for(int i=1;i<=len_a;i++) f[i]=tm[i];
    }
    for(int i=mx;i>0;i--)
    {
        printf("%c",a[idx-i+1]);
    }
    return 0;
}
