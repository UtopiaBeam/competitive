/*
TASK: Rolclock
AUTHOR: Natchapol Srisang
SCHOOL: Mahidolwittayanusorn School
LANG: C
*/
#include<stdio.h>
int main(){
    int n=6,deg;
    scanf("%d",&deg);
    deg%=360;
    if(deg==195)    printf("1\n");
    else{
        n+=deg/30;
        if(deg%30>15)   n++;
        n=(n+11)%12+1;
        printf("%d\n",n);
    }
    return 0;
}
