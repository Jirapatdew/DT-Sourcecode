#include<stdio.h>
#include<string.h>
#define MAX(a,b) ((a>b)?a:b)
using namespace std;

char s[100100],c[10];
int chk[30][30]={0};
int num[30]={0};

int main()
{
    int n;
    scanf("%s",s);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",c);
        chk[c[0]-'a'][c[1]-'a']=1;
        chk[c[1]-'a'][c[0]-'a']=1;
    }
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        int mx=1;
        for(int j=0;j<26;j++)
        {
            if(num[j]!=0&&chk[s[i]-'a'][j]==0) mx=MAX(mx,num[j]+1);
        }
        num[s[i]-'a']=MAX(mx,num[s[i]-'a']);
    }
    int mx=0;
    for(int i=0;i<26;i++) mx=MAX(mx,num[i]);
    printf("%d",len-mx);
    return 0;
}