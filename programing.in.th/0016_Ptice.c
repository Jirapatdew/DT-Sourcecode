#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,c[3]={0},max,i;
    char x[200];
    char Adrian[3]= {'A','B','C'};
    char Bruno[4]= {'B','A','B','C'};
    char Goran[6]= {'C','C','A','A','B','B'};
    scanf("%d\n",&n);
    for(i=0; i<n; i++) scanf("%c",&x[i]);
    for(i=0; i<n; i=i+3)
    {
        if(Adrian[0]==x[i]) ++c[0];
        if(Adrian[1]==x[i+1]) ++c[0];
        if(Adrian[2]==x[i+2]) ++c[0];
    }
    for(i=0; i<n; i=i+4)
    {
        if(Bruno[0]==x[i]) ++c[1];
        if(Bruno[1]==x[i+1]) ++c[1];
        if(Bruno[2]==x[i+2]) ++c[1];
        if(Bruno[3]==x[i+3]) ++c[1];
    }
    for(i=0; i<n; i=i+6)
    {
        if(Goran[0]==x[i]) ++c[2];
        if(Goran[1]==x[i+1]) ++c[2];
        if(Goran[2]==x[i+2]) ++c[2];
        if(Goran[3]==x[i+3]) ++c[2];
        if(Goran[4]==x[i+4]) ++c[2];
        if(Goran[5]==x[i+5]) ++c[2];
    }
    max=c[0];
    for(i=1;i<3;i++) if(max<c[i]) max=c[i];
    printf("%d",max);
    if(max==c[0]) printf("\nAdrian");
    if(max==c[1]) printf("\nBruno");
    if(max==c[2]) printf("\nGoran");
        return 0;
}
