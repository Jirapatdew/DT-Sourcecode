#include <stdio.h>

using namespace std;

int main()
{
    int Q,h;
    double H,M,O;
    char c[10];
    scanf("%d\n",&Q);
    for(int i=0;i<Q;i++)
    {
        scanf("%s",c);
        H=M=0;
        h=(c[0]-'0')*10+(c[1]-'0');
        h%=12;
        H=h*30+((c[3]-'0')*10+(c[4]-'0'))*0.5;
        M=((c[3]-'0')*10+(c[4]-'0'))*6;
        if(H>M)
        {
            O=H-M;
            if(O>180) O=360-O;
        }
        else
        {
            O=M-H;
            if(O>180) O=360-O;
        }
        printf("%.2lf\n",O);
    }
    return 0;
}
