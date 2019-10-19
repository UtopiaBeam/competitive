#include<stdio.h>
#include<math.h>

int main(){
    int n,i,product=1;
    scanf("%d",&n);
    for(i=2;i<=n;i++){
        product*=i;
        if(product%10==0) product/=10;
        product%=10;
    }
    printf("%d\n",product);
    return 0;
}
