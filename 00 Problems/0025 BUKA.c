#include<stdio.h>
#include<string.h>

int main()
{
    char A[120],B[120],oprt;
    int lena,lenb,check=0,i;
    scanf(" %s",A);
    scanf(" %c",&oprt);
    scanf(" %s",B);
    lena=strlen(A),lenb=strlen(B);
    if(oprt=='+')   check=1;
    if(lena>lenb)
    {
        if(check)
            for(i=0;i<lena;i++)
            {
                if(i==lena-lenb)   printf("1");
                else            printf("%c",A[i]);
            }
    }
    else if(lena<lenb)
    {
        if(check)
            for(i=0;i<lenb;i++)
            {
                if(i==lenb-lena)   printf("1");
                else            printf("%c",B[i]);
            }
    }
    else if(check)
        for(i=0;i<lena;i++)
        {
            if(i==0)    printf("2");
            else        printf("0");
        }

    if(!check)
    {
        printf("1");
        for(i=0;i<lena+lenb-2;i++)
            printf("0");
    }
    return 0;
}
