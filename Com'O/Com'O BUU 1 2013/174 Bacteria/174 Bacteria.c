#include<stdio.h>
#include<math.h>
int main(){
    long long n;
    int cnt=0,i;
    scanf("%lld",&n);
    for(i=1;i<=sqrt(n);i++)
        if(n%i==0)
            if(n/i==i)  cnt++;
            else        cnt+=2;
    printf("%d\n",cnt);
    return 0;
}
