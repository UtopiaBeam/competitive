#include<stdio.h>
int main(){
    int i;
    double sum=0,n;
    for(i=0;i<5;i++){
        scanf("%lf",&n);
        sum+=n/5.00;
    }
    printf("%.2lf\n",sum);
    return 0;
}
