#include<cstdio>
#include<cmath>
int a;
double b;
int main(){
    scanf("%d %lf",&a,&b);
    if(a+0.5>=b || a%5)   printf("%.2lf\n",b);
    else    printf("%.2lf\n",b-a-0.5);
    return 0;
}
