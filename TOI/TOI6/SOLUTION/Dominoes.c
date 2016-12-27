#include <stdio.h>
#include <stdlib.h>
int x[16] = {0};
int n;
int dt=0;
void print(int p)
{
    int i;
    for(i=0; i<p; i++)
        if(x[i]==1) printf("--\n");
        else
        {
            printf("||\n");
        }
    printf("E\n");
    dt++;
}
int domino(int total,int p)
{
    if(total==n) print(p);
    else if(total<n)
    {
        x[p]=1;
        domino(total+1,p+1);
        x[p]=2;
        domino(total+2,p+1);
    }
}
int main()
{
    int i,j,t;
    scanf("%d",&n);
    domino(0,0);
    //printf("%d",dt);
    return 0;
}
