#include<stdio.h>

int main()
{
    int num=6,deg;
    scanf("%d",&deg);

    num+=deg/30;
    if(deg%30>15)
        num++;
    else if(deg%30==15)
        if(deg/30==6)
            num=1;

    if(num%12==0)
        printf("12");

    else
        printf("%d",num%12);

    return 0;
}
