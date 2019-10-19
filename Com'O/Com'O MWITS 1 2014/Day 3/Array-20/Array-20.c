#include<stdio.h>
double a[5][5],sum=0.00;
int main(){
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++){
            scanf("%lf",&a[i][j]);
            sum+=a[i][j]/3.00;
        }
    printf("%.2lf %.2lf\n",sum,sum);
    return 0;
}
