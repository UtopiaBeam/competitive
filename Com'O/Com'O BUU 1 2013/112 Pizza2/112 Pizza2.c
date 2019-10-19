#include<stdio.h>
int main(){
    int q;
    long long p;
    scanf("%d",&q);
    while(q--){
        scanf("%lld",&p);
        printf("%lld\n",(p/2+1)*((p+3)/2));
    }
    return 0;
}
