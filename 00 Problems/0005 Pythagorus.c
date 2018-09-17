#include<stdio.h>
#include<math.h>
int main(){
    double a,b,ans;
    scanf("%lf %lf",&a,&b);
    ans=sqrt(a*a+b*b);
    printf("%.6lf\n",ans);
    return 0;
}
