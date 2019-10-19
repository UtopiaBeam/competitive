#include<cstdio>
int cnt[2],sum=0,n,k,a;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        cnt[a%2]++;
        sum+=a,sum%=2;
    }
    if(n==k){
        if(cnt[1]%2)    printf("Stannis\n");
        else    printf("Daenerys\n");
        return 0;
    }
    if(cnt[0]<cnt[1]){
        if((n-k)/2>=cnt[0])     sum+=(n-k)-cnt[0];
        else    sum=n-k;
    }
    else{
        if((n-k)/2>=cnt[1])    sum+=cnt[1];
        else    sum=n-k;
    }
    if(sum%2)   printf("Stannis\n");
    else    printf("Daenerys\n");
    return 0;
}
