#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int m,n;
    int i,j,k,w,p,a=0;
    int u=0,d=0,l=0,r=0,ur=0,ul=0,dr=0,dl=0;
    char data[26][26]= {'\0'},word[16]= {'\0'};
    scanf("%d%d",&n,&m);
    for(i=0; i<n; i++)
    {
        scanf("%s",data[i]);
        for(j=0; j<m; j++)
        {
            if(data[i][j]<'a') data[i][j]=data[i][j]+32;
        }
    }
    scanf("%d",&k);
    for(w=0; w<k; w++)
    {
        scanf("%s",word);
        int len=strlen(word);
        for(i=0; i<len; i++)
        {
            if(word[i]<'a') word[i]=word[i]+32;
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(data[i][j]==word[0])
                {
                    for(p=1; p<len; p++)
                    {
                        if((j+p)<=m&&data[i][j+p]==word[p]) r++;
                        if((j-p)>=0&&data[i][j-p]==word[p]) l++;
                        if((i+p)<=n&&data[i+p][j]==word[p]) d++;
                        if((i-p)>=0&&data[i-p][j]==word[p]) u++;
                        if((i-p)>=0&&(j+p)<=m&&data[i-p][j+p]==word[p]) ur++;
                        if((i-p)>=0&&(j-p)>=0&&data[i-p][j-p]==word[p]) ul++;
                        if((i+p)<=n&&(j-p)>=0&&data[i+p][j-p]==word[p]) dl++;
                        if((i+p)<=n&&(j+p)<=m&&data[i+p][j+p]==word[p]) dr++;
                    }
                    if(r==len-1||l==len-1||u==len-1||d==len-1||ur==len-1||ul==len-1||dr==len-1||dl==len-1)
                    {
                        a=1;
                        printf("%d %d\n",i,j);
                    }
                    u=0;
                    d=0;
                    l=0;
                    r=0;
                    ur=0;
                    ul=0;
                    dr=0;
                    dl=0;
                }
                if(a==1) break;
            }
            if(a==1) break;
        }
        a=0;
    }
    return 0;
}
