#include<stdio.h>

int main()
{
    int deg;
    scanf("%d",&deg);
        deg=deg%360;
    if(deg<0)
        deg=(deg%360)+360;

    if(deg==0||deg==180)
        printf("x-axis");
    else if(deg==90||deg==270)
        printf("y-axis");
    else if(deg>0 && deg<90)
        printf("1");
    else if(deg>90 && deg<180)
        printf("2");
    else if(deg>180 && deg<270)
        printf("3");
    else
        printf("4");
    return 0;
}
