#include<cstdio>
#define L long long
int n;
L k;
int main(){
    scanf("%d %I64d",&n,&k);
    L l=1,r=((L)1<<n)-1;
    while(n){
        L m=(l+r)/2;
        if(m==k){
            printf("%d\n",n);
            return 0;
        }
        if(k<m)     r=m;
        else        l=m+1;
        n--;
    }
}
