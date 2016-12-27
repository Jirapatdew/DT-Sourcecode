#include <stdio.h>
#include <stdlib.h>

int A[100006]= {0};
int B[100006]= {0};
int map[2][205][2]={0},p[2]={2,1};
int n,k;
int min(int a,int b)
{
    if(a<b) return a;
    else return b;
}
int walk(int i,int a)
{
    if(i>n) return 0;
    if((-1*k)==a) return walk(i+1,a+1)+A[i];
    if(k==a) return walk(i+1,a-1)+B[i];
    if((-1*k)<a&&a<k) return min(walk(i+1,a+1)+A[i],walk(i+1,a-1)+B[i]);
}
int main()
{

    int i,j;
    int t,l,ma=0,aa;
    scanf("%d",&t);
    for(l=0; l<t; l++)
    {
        scanf("%d%d",&n,&k);
        for(i=1; i<=n; i++) scanf("%d%d",&A[i],&B[i]);
        for(i=1; i<=n; i++)
        {
            aa=(ma+1)%2;
            p[aa]=1;
            for(j=1; j<p[ma]; j++)
            {
                if((-1*k)>map[ma][j][1]-1)
                {
                    map[aa][p[aa]][1]=map[ma][j][1]+1;
                    map[aa][p[aa]][0]=map[ma][j][0]+A[i];
                    p[aa]++;
                } //walk(i+1,a+1)+A[i];
                if(k<map[ma][j][1]+1)
                {
                    map[aa][p[aa]][1]=map[ma][j][1]-1;
                    map[aa][p[aa]][0]=map[ma][j][0]+B[i];
                    p[aa]++;
                }//walk(i+1,a-1)+B[i];
                if((-1*k)<a&&a<k)
                {

                }
            }
        }

        printf("%d\n",walk(1,0));
    }

    return 0;
}
