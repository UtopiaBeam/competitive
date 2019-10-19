#include<stdio.h>
int main(){
    double d,Vr,Vt,Vf;
    scanf("%lf %lf %lf %lf",&d,&Vr,&Vt,&Vf);
    printf("%.2lf\n",(d*Vf)/(Vt-Vr));
    return 0;
}
