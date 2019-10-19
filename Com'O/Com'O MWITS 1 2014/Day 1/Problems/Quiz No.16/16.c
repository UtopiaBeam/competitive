#include<stdio.h>
int main(){
    int n,i;
    double sum=0,a;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lf",&a);
        sum+=a/n;
    }
    printf("%.2lf\n",sum);
    return 0;
}
