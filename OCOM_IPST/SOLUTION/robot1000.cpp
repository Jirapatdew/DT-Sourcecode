#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char a[1000];
    int x=0,y=0;
    gets(a);
    int len=strlen(a);
    for(int i=0;i<len;i++)
    {
        if(a[i]=='N') y++;
        else if(a[i]=='S') y--;
        else if(a[i]=='E') x++;
        else if(a[i]=='W') x--;
        else x=y=0;
    }
    printf("%d %d",x,y);
    return 0;
}
