/*
TASK: NSW
LANG: C
AUTHOR: Jirapat Atiwattanachai
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char key[3]= {'\0'},code[257]= {'\0'};
    int x1[9]= {0},x2[9]= {0},x3[9]= {0};
    int i,len,j;
    scanf("%s",key);
    int n1=key[0]-48,n2=key[1]-48,n3=key[2]-48;
    for(i=0; i<9; i++)
    {
        if(n1==10) n1=1;
        if(n2==10) n2=1;
        if(n3==10) n3=1;
        x1[i]=n1++;
        x2[i]=n2++;
        x3[i]=n3++;
    }
    scanf("%s",code);
    len=strlen(code);
    printf("%d",x3[x2[x1[code[0]-49]-1]-1]);
    for(j=1; j<len; j++)
    {
        if(key[0]=='9') n1=x1[0];//มี ifเพราะ ถ้า key=9 จะำ error เพราะ array มีแค่ 0-8
        else n1=x1[key[0]-48];
        n2=x2[8];
        if(key[2]=='9') n3=x3[0];
        else n3=x3[key[2]-48];
        for(i=0; i<9; i++)
        {
            if(n1==10) n1=1;
            if(n2==10) n2=1;
            if(n3==10) n3=1;
            x1[i]=n1++;
            x2[i]=n2++;
            x3[i]=n3++;
        }
        printf("%d",x3[x2[x1[code[j]-49]-1]-1]);
    }
    return 0;
}
