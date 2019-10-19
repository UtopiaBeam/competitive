#include<cstdio>
long long ans=0,n,cnt=0,t;
long long f(int x){
    if(x==0)    return 1;
    int tmp=f(x/2);
    if(x%2)     return 10*tmp*tmp;
    return tmp*tmp;
}
int main(){
    scanf("%I64d",&n);
    t=n;
    while(t)    cnt++,t/=10;
    for(long long i=1,j=9;i<cnt;i++,j*=10)
        ans+=i*j;
    printf("%I64d\n",ans+(n-f(cnt-1)+1)*cnt);
    return 0;
}
