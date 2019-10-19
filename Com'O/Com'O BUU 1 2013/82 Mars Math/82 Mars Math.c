#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    int base,lena,lenb,lenc,j,check=0;
    int a10=0,b10=0,c10=0;
    char a[120],b[120],c[120];
    gets(a);
    gets(b);
    gets(c);
    lena=strlen(a),lenb=strlen(b),lenc=strlen(c);
    for(base=2;base<=36;base++)
    {
        for(j=0;j<lena;j++)
            if(isalpha(a[j]))   a[j]=a[j]-55;
        for(j=0;j<lena;j++)
            a10=(a10*base)+a[j];
        for(j=0;j<lenb;j++)
            if(isalpha(b[j]))   b[j]=b[j]-55;
        for(j=0;j<lenb;j++)
            b10=(b[j]*base)+b[j];
        for(j=0;j<lenc;j++)
            if(isalpha(c[j]))   c[j]=c[j]-55;
        for(j=0;j<lenc;j++)
            c10=(c10*base)+c[j];
        /*if(a10+b10==c10)
        {
            printf("%d\n",base);
            return 0;
        }
        else check=1;*/
    }
    if(check)   printf("no\n");
    return 0;
}
