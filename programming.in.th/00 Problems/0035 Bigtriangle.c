#include<stdio.h>
#include<math.h>
double x[110],y[110],max=0.000,a;
int main(){
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lf %lf",&x[i],&y[i]);
    for(i=0;i<n-2;i++)
        for(j=1;j<n-1;j++)
            for(k=2;k<n;k++){
                a=fabs(x[i]*y[j]+x[j]*y[k]+x[k]*y[i]-x[j]*y[i]-x[k]*y[j]-x[i]*y[k])/2.000;
                if(max<a)   max=a;
            }
    printf("%.3lf\n",max);
    return 0;
}
