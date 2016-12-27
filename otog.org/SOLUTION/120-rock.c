#include <stdio.h>
#include <stdlib.h>

int data[200]={0};
int map[150][150]={0};
int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
    int n;
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=2*n;i++) scanf("%d",&data[i]);
    //eat(1,2*n,0);
    for(k=2;k<=2*n;k+=2)
    {
        for(i=1,j=k;j<=2*n;i++,j++)
        {
            if(j-i==1) {map[i][j]=max(data[i],data[j]);continue;}
            map[i][j]=max(map[i][j],map[i+2][j]+data[i]);
            map[i][j]=max(map[i][j],map[i][j-2]+data[j]);
            map[i][j]=max(map[i][j],map[i+1][j-1]+data[i]);
            map[i][j]=max(map[i][j],map[i+1][j-1]+data[j]);
        }
    }
    printf("%d",map[1][2*n]);
    return 0;
}
/*int eat(int i,int j,int sum) recurence
{
    if(i<j)
    {
        eat(i+2,j,sum+data[i]);
        eat(i,j-2,sum+data[j]);
        eat(i+1,j-1,sum+data[i]);
        eat(i+1,j-1,sum+data[j]);
    }
    else
    {
        if(sum>max)max=sum;
    }
}*/
