#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    char data[100][100]={"","Washington"
,"Adams"
,"Jefferson"
,"Madison"
,"Monroe"
,"Adams"
,"Jackson"
,"Van Buren"
,"Harrison"
,"Tyler"
,"Polk"
,"Taylor"
,"Fillmore"
,"Pierce"
,"Buchanan"
,"Lincoln"
,"Johnson"
,"Grant"
,"Hayes"
,"Garfield"
,"Arthur"
,"Cleveland"
,"Harrison"
,"Cleveland"
,"McKinley"
,"Roosevelt"
,"Taft"
,"Wilson"
,"Harding"
,"Coolidge"
,"Hoover"
,"Roosevelt"
,"Truman"
,"Eisenhower"
,"Kennedy"
,"Johnson"
,"Nixon"
,"Ford"
,"Carter"
,"Reagan"
,"Bush"
,"Clinton"
,"Bush"
,"Obama"
};
    scanf("%d",&n);
    printf("%s",data[n]);
    return 0;
}