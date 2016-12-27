#include<stdio.h>
#include<string.h>
main()
{
    int a,b,c;
    char s[4];
    scanf("%d%d%d",&a,&b,&c);
    scanf("%s",s);
    if(a>0&&b>0&&c>0&&a<=100&&b<=100&&c<=100)
    {
        if(strcmp(s,"ABC")==0)
        {
            if(a>=b&&b>=c)printf("%d %d %d",c,b,a);
            else if(b>=a&&a>=c)printf("%d %d %d",c,a,b);
            else if(c>=b&&b>=a)printf("%d %d %d",a,b,c);
            else if(b>=c&&c>=a)printf("%d %d %d",a,c,b);
            else if(c>=a&&a>=b)printf("%d %d %d",b,a,c);
            else if(a>=c&&c>=b)printf("%d %d %d",b,c,a);
        }
        else if(strcmp(s,"ACB")==0)
        {
            if(a>=b&&b>=c)printf("%d %d %d",c,a,b);
            else if(b>=a&&a>=c)printf("%d %d %d",c,b,a);
            else if(c>=b&&b>=a)printf("%d %d %d",a,c,b);
            else if(b>=c&&c>=a)printf("%d %d %d",a,b,c);
            else if(c>=a&&a>=b)printf("%d %d %d",b,c,a);
            else if(a>=c&&c>=b)printf("%d %d %d",b,a,c);
        }
        else if(strcmp(s,"BAC")==0)
        {
            if(a>=b&&b>=c)printf("%d %d %d",b,c,a);
            else if(b>=a&&a>=c)printf("%d %d %d",a,c,b);
            else if(c>=b&&b>=a)printf("%d %d %d",b,a,c);
            else if(b>=c&&c>=a)printf("%d %d %d",c,a,b);
            else if(c>=a&&a>=b)printf("%d %d %d",a,b,c);
            else if(a>=c&&c>=b)printf("%d %d %d",c,b,a);
        }
        else if(strcmp(s,"BCA")==0)
        {
            if(a>=b&&b>=c)printf("%d %d %d",b,a,c);
            else if(b>=a&&a>=c)printf("%d %d %d",a,b,c);
            else if(c>=b&&b>=a)printf("%d %d %d",b,c,a);
            else if(b>=c&&c>=a)printf("%d %d %d",c,b,a);
            else if(c>=a&&a>=b)printf("%d %d %d",a,c,b);
            else if(a>=c&&c>=b)printf("%d %d %d",c,a,b);
        }
        else if(strcmp(s,"CAB")==0)
        {
            if(a>=b&&b>=c)printf("%d %d %d",a,c,b);
            else if(b>=a&&a>=c)printf("%d %d %d",b,c,a);
            else if(c>=b&&b>=a)printf("%d %d %d",c,a,b);
            else if(b>=c&&c>=a)printf("%d %d %d",b,a,c);
            else if(c>=a&&a>=b)printf("%d %d %d",c,b,a);
            else if(a>=c&&c>=b)printf("%d %d %d",a,b,c);
        }
        else if(strcmp(s,"CBA")==0)
        {
            if((a>=b)&&(b>=c))printf("%d %d %d",a,b,c);
            else if(b>=a&&a>=c)printf("%d %d %d",b,a,c);
            else if(c>=b&&b>=a)printf("%d %d %d",c,b,a);
            else if(b>=c&&c>=a)printf("%d %d %d",b,c,a);
            else if(c>=a&&a>=b)printf("%d %d %d",c,a,b);
            else if(a>=c&&c>=b)printf("%d %d %d",a,c,b);
        }
    }
}
