/*
TASK: Possess
AUTHOR: Natchapol Srisang
SCHOOL: Mahidolwittayanusorn School
LANG: C
*/
#include<cstdio>
#include<cmath>
int main(){
    double k,d,r,x,y;
    scanf("%lf %lf",&k,&d);
    r=1.0+d/(sqrt(15.0*15.0+(40.0-k)*(40.0-k)));
    x=15*r;
    if(k<=40.0)     y=k+(40.0-k)*r;
    else    y=k-(k-40.0)*r;
    x=fmod(x+120000000000.0,120.0),y=fmod(y+200000000000.0,200.0);
    if(x>60.0)    x=120.0-x;
    if(y>100.0)   y=200.0-y;
    printf("%.1lf %.1lf\n",x,y);
    return 0;
}

