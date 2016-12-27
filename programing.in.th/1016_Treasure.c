#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//cos(dregre*M_PI/180);
//function cos มุมเป็นเรเดี่ยน
int main()
{
    char data[6]= {'\0'};
    int t;
    double x=0,y=0,tmp;
    char direction[3]= {'\0'};
    while(1)
    {
        scanf("%s",data);
        if(data[0]=='*') break;
        int len=strlen(data);
        if(data[len-2]>='0'&&data[len-2]<='9') t=1;
        else t=2;
        if(t==1)
        {
            direction[0]=data[len-1];
            data[len-1]='\0';
        }
        else
        {
            direction[0]=data[len-2];
            data[len-2]='\0';
            direction[1]=data[len-1];
            data[len-1]='\0';
        }
        tmp=atoi(data);
        if(t==1)
        {
            if(direction[0]=='N') y+=tmp;
            else if(direction[0]=='S') y-=tmp;
            else if(direction[0]=='E') x+=tmp;
            else if(direction[0]=='W') x-=tmp;
        }
        else
        {
            tmp*=cos(45*M_PI/180);
            if(direction[0]=='N'&&direction[1]=='E') {x+=tmp;y+=tmp;}
            else if(direction[0]=='N'&&direction[1]=='W') {x-=tmp;y+=tmp;}
            else if(direction[0]=='S'&&direction[1]=='E') {x+=tmp;y-=tmp;}
            else if(direction[0]=='S'&&direction[1]=='W') {x-=tmp;y-=tmp;}

        }
    }
    printf("%.3lf %.3lf\n",x,y);
    printf("%.3lf",sqrt((x*x)+(y*y)));
    return 0;
}
