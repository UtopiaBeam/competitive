#include<cstdio>
#include<cmath>
int t,a[35];
int main(){
    scanf("%d",&t);
    int n=log2(t+1);
    t-=(1<<n)-1;
    for(int i=0;i<n;i++){
        a[i]=t%2;
        t/=2;
    }
    for(int i=n-1;i>=0;i--)
        printf("%d",(1-a[i])*4+a[i]*7);
    return 0;
}
