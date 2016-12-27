#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char a[1000];
    char b[]="UUDDLRLRBAS";
    scanf("%s",a);
    int lena=strlen(a),lenb=strlen(b),j,p=0;
    for(int i=0;i<lena;i++)
    {
        if(a[i]=='U')
        {
            for(j=i;j<lena;j++) if(a[j]!=b[j-i]) break;
            if(j==lena)
            {
                for(j=j-i;j<lenb;j++) printf("%c",b[j]);
                p=1;
                break;
            }
        }
    }
    if(p==0) printf("%s",b);
    return 0;
}
