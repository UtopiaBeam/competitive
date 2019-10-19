#include<cstdio>
int a[6];
int main(){
    for(int i=0;i<6;i++)
        scanf("%d",&a[i]);
    printf("%d\n",(a[1]+a[2]+a[3])*(a[1]+a[2]+a[3])-a[1]*a[1]-a[3]*a[3]-a[5]*a[5]);
    return 0;
}
