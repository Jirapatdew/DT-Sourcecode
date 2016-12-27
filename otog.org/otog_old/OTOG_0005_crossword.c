#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int h,w;
    int i,j,num,x=0,y=0,total=0;
    int n;
    char data[105][105]= {'\0'};
    char word[105][105]= {'\0'},tmp;
    int len[105]= {0};
    scanf("%d%d\n",&h,&w);
    for(i=0; i<h; i++) gets(data[i]);
    x=h-1;
    y=w-1;
    for(i=0; i<h; i++)
    {
        for(j=0; j<w; j++)
        {
            if(data[i][j]=='.')
            {
                num=0;
                if(i>0&&data[i-1][j]=='.') num++;
                if(i<h-1&&data[i+1][j]=='.') num++;
                if(j>0&&data[i][j-1]=='.') num++;
                if(j<w-1&&data[i][j+1]=='.') num++;
                if(num>2)
                {
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        if(num>2) break;
    }
    scanf("%d\n",&n);
    for(i=0; i<n; i++)
    {
        gets(word[i]);
        len[i]=strlen(word[i]);
    }
    for(i=0; i<n; i++) //ตั้ง
    {
        if(len[i]==h)
        {
            tmp=word[i][x];
            for(j=0; j<n; j++)
            {
                if(i!=j&&len[j]==w&&tmp==word[j][y]) total++;
            }
        }
    }
    printf("%d",total);
    return 0;
}
