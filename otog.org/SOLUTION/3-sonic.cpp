#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

char a[1000];
int chk[50]={0};
int cmp(const void*a,const void*b)
{
    return *(int*)b-*(int*)a;
}
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        gets(a);
        int len=strlen(a),sum=0;
        for(int j=0;j<=25;j++) chk[j]=0;
        for(int j=0;j<len;j++)
        {
            if('a'<=a[j]&&a[j]<='z') a[j]=a[j]-'a'+'A';
            chk[a[j]-'A']++;
        }
        qsort(chk,26,sizeof(int),cmp);
        int j=0;
        while(chk[j]>0)
        {
            sum+=chk[j]*(26-j);
            j++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
