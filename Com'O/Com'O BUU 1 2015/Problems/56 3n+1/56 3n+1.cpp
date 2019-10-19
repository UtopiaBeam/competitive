#include<cstdio>
long long a,b,t,mx=1;
int main(){
    scanf("%lld %lld",&a,&b);
    if(a>b)     t=a,a=b,b=t;
    while(a<=b){
        int t=a,cnt=1;
        while(t>1){
            if(t%2)     t=3*t+1;
            else    t/=2;
            cnt++;
        }
        if(mx<cnt)  mx=cnt;
        a++;
    }
    printf("%lld\n",mx);
    return 0;
}
