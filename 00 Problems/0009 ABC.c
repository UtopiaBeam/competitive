#include<stdio.h>

int main()
{
    int a,b,c,A,C,B,i;
    char ch;
    scanf("%d %d %d",&a,&b,&c);
    A=a;
    C=a;

    if(A>b)
        A=b;
    if(A>c)
        A=c;

    if(C<b)
        C=b;
    if(C<c)
        C=c;

    if(A==a && C==b||A==b && C==a)
        B=c;
    else if(A==a && C==c||A==c && C==a)
        B=b;
    else
        B=a;

    for(i=1;i<=4;i++)
    {
        scanf("%c",&ch);
        if(ch=='A')
            printf("%d ",A);
        else if(ch=='B')
            printf("%d ",B);
        else if(ch=='C')
            printf("%d ",C);
    }
    return 0;
}
