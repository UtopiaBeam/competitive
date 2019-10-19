/*
TASK: Intro017
AUTHOR: Natchapol Srisang
SCHOOL: Mahidolwittayanusorn School
LANG: C
*/
#include<cstdio>
#include<cmath>
int main(){
    double x1,x2,x3,y1,y2,y3,k,a;
    scanf("%lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&k);
    a=0.5*(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2),a*=1-2*(a<0);
    printf("%.2lf %.2lf\n",a,M_PI*k*k+k*(sqrt(pow(x1-x2,2)+pow(y1-y2,2))+sqrt(pow(x2-x3,2)+pow(y2-y3,2))+sqrt(pow(x1-x3,2)+pow(y1-y3,2))));
    return 0;
}


