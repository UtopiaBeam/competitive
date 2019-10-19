/*
TASK: Important
AUTHOR: Natchapol Srisang
SCHOOL: Mahidolwittayanusorn School
LANG: C
*/
#include<stdio.h>
#define a 125000.00
int main(){
    double x0=0,y0=0,x=0,y=0;
    scanf("%lf %lf",&x0,&y0);
    if(x0==0){
        if(y0<=250)     x=a/(500-y0),y=500-x;
        else    x=a/y0,y=0;
    }
    else if(y0==0){
        if(x0<=250)     y=a/(500-x0),x=500-y;
        else    y=a/x0,x=0;
    }
    else{
        if(x0<=250)     x=500-a/y0,y=0;
        else            x=0,y=500-a/x0;
    }
    printf("%.2lf %.2lf",x,y);
    return 0;
}
