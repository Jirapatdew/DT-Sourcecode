#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int a,b,T;
    scanf("%d",&T);
    while(T>0)
    {
        scanf("%d/%d",&a,&b);
        while(a!=1||b!=1)
        {
            if(a>b) {printf("R");a-=b;}
            else {printf("L");b-=a;}
            swap(a,b);
        }
        printf("\n");
        T--;
    }
    return 0;
}
