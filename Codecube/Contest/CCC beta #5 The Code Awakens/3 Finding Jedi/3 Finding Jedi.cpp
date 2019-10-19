#include<cstdio>
int n,sum,t;
long long a[1000002],ans=0;
int main(){
    scanf("%d %d",&n,&sum);
    while(n--){
        scanf("%d",&t);
        a[t]++;
    }
    if(sum%2==0)
        ans=(a[sum/2]*(a[sum/2]-1))/2;
    for(int i=0;i<sum/2+(sum%2);i++)
        ans+=a[i]*a[sum-i];
    printf("%lld\n",ans);
    return 0;
}
