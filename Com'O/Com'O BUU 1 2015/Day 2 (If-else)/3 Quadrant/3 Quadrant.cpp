/*
TASK: Quadrant
AUTHOR: Natchapol Srisang
SCHOOL: Mahidolwittayanusorn School
LANG: C
*/
#include<cstdio>
#include<cmath>
int main(){
    double a;
    scanf("%lf",&a);
    a=fmod(a+36000.0,360.0);
    if(a==0.0 || a==180.0)  printf("x-axis\n");
    else if(a==90.0 || a==270.00)   printf("y-axis\n");
    else    printf("%.0lf\n",ceil(a/90.00));
    return 0;
}
