#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void* a, const void* b)
{
    return strcmp((char*)a, (char*)b);
}
int main()
{
    int n, i;
    char names[1000][100];
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        scanf("%s", names[i]);
    }
    qsort(names, n, 100*sizeof(char), compare);
    for (i=0; i<300; i++)
    {
        printf("%s\n", names[i]);
    }
    return 0;
}

