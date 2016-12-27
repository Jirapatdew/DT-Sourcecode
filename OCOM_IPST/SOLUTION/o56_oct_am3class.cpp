#include <stdio.h>

using namespace std;

struct point
{
    int r,g,b;
}pic[105][105];
int main()
{
    int w,h;
    int sum=0;
    scanf("%d%d",&w,&h);
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++) scanf("%d%d%d",&pic[i][j].r,&pic[i][j].g,&pic[i][j].b);
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++) sum+=pic[i][j].r+pic[i][j].g+pic[i][j].b;
    if(sum>=4500000) printf("3\n");
    else if(sum<=2250000) printf("M\n");
    else printf("A\n");
    return 0;
}
