#include<cstdio>
int n,m,t;
long long a[12],ans=0;
int main(){
    scanf("%d %d",&n,&m);
    while(n--){
        scanf("%d",&t);
        a[t]++;
    }
    for(int i=1;i<m;i++)
        for(int j=i+1;j<=m;j++)
            ans+=a[i]*a[j];
    printf("%I64d\n",ans);
    return 0;
}
