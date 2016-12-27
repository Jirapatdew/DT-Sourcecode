#include<stdio.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

void strrevv(char b[],char a[])
{
	int i=strlen(a),k;

	for(k=0 ; k<i ; k++)
		b[k] = a[(i-1)-k];

	b[i] = '\0';
}

void strupper(char a[])
{
	int i=strlen(a);

	for(i-- ; i>=0 ; i--)
		if(a[i] >= 'a' && a[i] <= 'z')
			a[i] = a[i]-(97-65);
}

int main()
{
	int len, pali=FALSE, doupali=FALSE;
	char str[202],a[202],b[202],c[102],d[102];

	gets(str);

	strcpy(a,str);
	strupper(a);
	strrevv(b,a);

	pali = !strcmp(a,b);

	if(pali == TRUE)
	{
		len=strlen(str);

        str[len/2] = '\0';

		strcpy(c,str);
		strupper(c);
		strrevv(d,c);

		doupali = !strcmp(c,d);
	}

	if(doupali == TRUE)
		printf("Double Palindrome ");
	else if(pali == TRUE)
		printf("Palindrome");
	else
		printf("No");

	return 0;
}
