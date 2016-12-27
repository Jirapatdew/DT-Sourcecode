#include <stdio.h>

using namespace std;

int main()
{
    int H,M;
    scanf("%d%d",&H,&M);
    M-=45;
    if(M<0)
    {
        M=60+M;
        H--;
        if(H<0) H=23;
    }
    printf("%d %d",H,M);
    return 0;
}
