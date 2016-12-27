#include <stdio.h>
#include <stdlib.h>
#define MAX_n 100500

using namespace std;

int a[MAX_n]={0},b[MAX_n]={0};
int chk[MAX_n]={0},num=0;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    for(int i=0;i<n;i++)
    {
        (chk[a[i]]==0)?num++:num--;
        chk[a[i]]++;
        (chk[b[i]]==0)?num++:num--;
        chk[b[i]]--;
        if(num==0) {printf("%d",i+1);break;}
    }
    return 0;
}
