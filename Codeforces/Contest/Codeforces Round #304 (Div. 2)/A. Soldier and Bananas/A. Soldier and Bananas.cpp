#include<cstdio>
long long n,k,w;
int main(){
    scanf("%I64d %I64d %I64d",&w,&n,&k);
    printf("%I64d\n",(w*k*(k+1))/2-n<0? 0:(w*k*(k+1))/2-n);
    return 0;
}
