#include <stdio.h>
#include <stdlib.h>
#define pi 3.14159265358979323846264338327950288419716939937510

int main()
{
    double R;
    scanf("%lf",&R);
    printf("%.6lf\n",pi*R*R);
    printf("%.6lf\n",R*R*2);
    return 0;
}
