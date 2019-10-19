#include<cstdio>
#include<cmath>
int n,t;
double a[100002]={1.0};
int main(){
    for(int i=1;i<=100000;i++)
        a[i]=a[i-1]+log10(i);
    scanf("%d",&n);
    while(n--){
        scanf("%d",&t);
        printf("%.0lf\n",floor(a[t]));
    }
    return 0;
}
