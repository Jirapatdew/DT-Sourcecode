#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const  void*a,const void*b)
{
    char *aa=(char*)a;
    char *bb=(char*)b;
    return strcmp(aa,bb);
}
int main()
{
    int n,i,j,k;
    char data[25005][25]= {'\0'};
    char ans[150000]= {'\0'};
    char st[100]= {'\0'};
    int p=0,sttmp=-1;
    int len[25005]= {0},len_st,max,tmp;
    scanf("%d\n",&n);
    for(i=0; i<n; i++)
    {
        gets(data[i]);
    }
    qsort(data,n,sizeof(data[0]),cmp);

    len[0]=strlen(data[0]);
    tmp=0;
    max=len[0];
    for(i=1; i<n; i++)
    {
        len[i]=strlen(data[i]);
        if(len[i]>max)
        {
            max=len[i];
            tmp=i;
        }
    }

    for(i=0; i<n; i++)
    {
        if(data[i][0]==data[tmp][0]&&i<=tmp)
        {
            if(sttmp==-1) sttmp=i;
            continue;
        }
        if(p==0)//ตัวแรก
        {
            strcpy(ans,data[i]);
            p=len[i];
            ans[p++]='P';
            strcpy(st,data[i]);
            continue;
        }
        for(j=0; j<len[i]; j++) if(data[i][j]!=st[j]) break;//ไม่มีกรณีที่คำเหมือนกัน
        len_st=strlen(st);
        for(k=j;k<len_st;k++) ans[p++]='-';
        for(k=j;k<len[i];k++) ans[p++]=data[i][k];
        ans[p++]='P';
        strcpy(st,data[i]);
    }
    for(i=sttmp; i<=tmp; i++)//ไล่ทำตัวมากที่ข้ามมา
    {
        for(j=0; j<len[i]; j++) if(data[i][j]!=st[j]) break;//ไม่มีกรณีที่คำเหมือนกัน
        len_st=strlen(st);
        for(k=j;k<len_st;k++) ans[p++]='-';
        for(k=j;k<len[i];k++) ans[p++]=data[i][k];
        ans[p++]='P';
        strcpy(st,data[i]);
    }
    printf("%d\n",p);
    for(i=0;i<p;i++) printf("%c\n",ans[i]);
    return 0;
}
