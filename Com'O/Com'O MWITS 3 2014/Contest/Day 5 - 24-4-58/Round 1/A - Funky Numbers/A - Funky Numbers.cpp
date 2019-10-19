#include<cstdio>
long long n;
long long f(int i){
    return (i*(i+1))/2;
}
bool bs(long long str,long long end,long long v){
    if(str>end)     return 0;
    long long mid=(str+end)/2;
    if(v==f(mid))   return mid;
    if(v<f(mid))    return bs(str,mid-1,v);
    return bs(mid+1,end,v);
}
int main(){
    scanf("%I64d",&n);
    for(long long i=1;i<=50000;i++){
        long long in=bs(1,n,n-f(i));
        if(in>0){
            printf("YES\n");    return 0;
        }
    }
    printf("NO\n");
    return 0;
}
