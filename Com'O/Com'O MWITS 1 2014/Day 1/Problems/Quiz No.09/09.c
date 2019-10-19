#include<stdio.h>
int main(){
    double a,b,c,x;
    scanf("%lf %lf %lf",&a,&b,&c);
    x=(a+b+c)/3.00;
    if(a<x)         a*=1.10;
    else if(a>x)    a*=1.05;
    else            a*=1.07;
    if(b<x)         b*=1.10;
    else if(b>x)    b*=1.05;
    else            b*=1.07;
    if(c<x)         c*=1.10;
    else if(c>x)    c*=1.05;
    else            c*=1.07;
    printf("%lf %lf %lf\n",a,b,c);
    return 0;
}
