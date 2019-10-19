#include<cstdio>
int n,k,a,m,lim=0,b[10005]={0,1},dp[10005],max=0;
int main(){
    scanf("%d %d %d",&n,&k,&a);
    while(n--){
        scanf("%d",&m);
        lim+=m;
        if(n)  b[lim+1]=1;
    }
    for(int i=2;i<=lim;i++)
        b[i]+=b[i-1];
    for(int i=1;i<=lim;i++){
        int cnt=0;
        dp[i]=1;
        while(cnt<k-1 && i+(cnt+1)*a<=lim){
            if(b[i+cnt*a]!=b[i+(cnt+1)*a])
                dp[i]++;
            cnt++;
        }
    }
    for(int i=1;i<=lim;i++)
        if(dp[max]<dp[i])   max=i;
    printf("%d %d\n",max,dp[max]);
    return 0;
}
