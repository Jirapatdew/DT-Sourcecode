#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,k;
    long long total=0,x;
    char ch[100005][5]={'\0'};
    int one,two,three;
    int data[11][11][11]={0};
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
        gets(ch[i]);
        one=ch[i][0]-'0';
        two=ch[i][1]-'0';
        three=ch[i][2]-'0';
        data[one][10][10]++;
        data[10][two][10]++;
        data[10][10][three]++;
        data[one][two][10]++;
        data[10][two][three]++;
        data[one][10][three]++;
        data[one][two][three]++;
    }
    for(i=0;i<n;i++)
    {
        one=ch[i][0]-'0';
        two=ch[i][1]-'0';
        three=ch[i][2]-'0';
        data[one][10][10]--;
        data[10][two][10]--;
        data[10][10][three]--;
        data[one][two][10]--;
        data[10][two][three]--;
        data[one][10][three]--;
        data[one][two][three]--;
        x=(long long)data[one][10][10]+data[10][two][10]+data[10][10][three];
        x=x-data[one][two][10]-data[10][two][three]-data[one][10][three]+data[one][two][three];
        total+=x;

    }
    printf("%lld",total);
    return 0;
}
