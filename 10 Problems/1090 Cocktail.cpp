#include<cstdio>
#include<cstring>
bool chk[100005];
long long ans=0,cnt[100005];
int main(){
    int n,m;
    memset(chk,false,sizeof(chk));
    scanf("%d",&n);
    while(n--){
        int num;
        scanf("%d",&num);
        chk[num]=true,cnt[num]++;
    }
    scanf("%d",&m);
    for(int i=0;i<=m/2;i++){
        if(2*i==m && chk[i]){
            ans+=(cnt[i]*(cnt[i]-1))/2;
        }
        else if(chk[i] && chk[m-i])
            ans+=cnt[i]*cnt[m-i];
    }
    printf("%lld\n",ans);
    return 0;
}
