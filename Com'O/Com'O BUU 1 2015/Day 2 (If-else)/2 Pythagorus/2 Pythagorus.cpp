/*
TASK: Pythagorus
AUTHOR: Natchapol Srisang
SCHOOL: Mahidolwittayanusorn School
LANG: C
*/
#include<cstdio>
#include<cmath>
int main(){
    double a,b,c;
    scanf("%lf %lf %lf",&a,&b,&c);
    if(!a)    printf("%.2lf\n",sqrt(c*c-b*b));
    else if(!b)    printf("%.2lf\n",sqrt(c*c-a*a));
    else    printf("%.2lf\n",sqrt(a*a+b*b));
    return 0;
}
