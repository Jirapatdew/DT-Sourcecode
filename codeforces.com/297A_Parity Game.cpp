#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char in[1010];
    int len,n_a=0,n_b=0;
    scanf("%s",in);
    len=strlen(in);
    for(int i=0;i<len;i++) if(in[i]=='1') n_a++;
    scanf("%s",in);
    len=strlen(in);
    for(int i=0;i<len;i++) if(in[i]=='1') n_b++;
    if(n_a%2==1) n_a++;
    if(n_a>=n_b) printf("YES");
    else printf("NO");
    return 0;
}