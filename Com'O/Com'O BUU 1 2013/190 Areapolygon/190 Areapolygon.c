#include<stdio.h>
#include<math.h>
double x[102],y[102],a=0.0;
int n,i,j;
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lf %lf",&x[i],&y[i]);
    x[n]=x[0],y[n]=y[0];
    for(i=0;i<n;i++)    a+=x[i]*y[i+1];
    for(i=1;i<=n;i++)   a-=x[i]*y[i-1];
    printf("%.2lf\n",0.5*fabs(a));
    return 0;
}
