#include <stdio.h>
#include <stdlib.h>

int main()
{
    int G[100][100]={0},p[100]={0},Q[100]={0},s[100]={0},x[100]={0};
    //G=��ҿ   p=���  Q=���  s=ʶҹ�(  0=�բ�� 1=����  2=�մ� )  x=��Ǫ����ش�͡���������
    int i,n,a,b=0,num=0,out,l;//begin=���˹觺��ش�ͧ Queue num �͡�ӹǹ��Ƿ�������Q
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        scanf("%d",&G[a][x[a]]);
        x[a]++;
    }
    Q[b++]=1;//��������0
    s[1]=1;
    num=1;
    l=0;
    while(num>0)
    {
        out=Q[l];
        l++;
        num--;
        printf("%d\n",out);
        s[out]=2;
        for(i=0;i<x[out];i++)
        {
            if(s[G[out][i]]==0)
            {
                Q[b++]=G[out][i];
                s[G[out][i]]=1;
                num++;
            }
        }
    }


    return 0;
}
/*
11
1 2
1 3
1 4
2 5
2 6
3 4
4 7
5 8
7 9
8 6
9 6
*/
