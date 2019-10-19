#include<stdio.h>

int main()
{
    int a,b,c,d,e,total;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    total=a*c+b*d;
    if(total>=e)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}
