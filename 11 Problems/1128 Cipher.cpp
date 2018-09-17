#include<stdio.h>
unsigned long long a,ans=0;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%llu",&a);
        ans+=(a*(n-i)*(n-i+1)/2)%2553;
    }
    printf("%llu\n",ans%2553);
    return 0;
}
