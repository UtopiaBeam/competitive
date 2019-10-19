#include<cstdio>
#define MOD (int)(1e9-1)
int n,k,a[80002],ans=0;
int ft[42][80002],t;
void ud(int x,int t,int v){
    for(;x<=n;x+=-x&x)  ft[t][x]=(ft[t][x]+v)%MOD;
}
int qr(int x,int t){
    int sum=0;
    for(;x;x-=-x&x)     sum=(sum+ft[t][x])%MOD;
    return sum;
}
void debug(){
    for(int j=1;j<=k;j++){
        for(int i=1;i<=n;i++)
            printf("%d ",qr(i,j));
        printf("\n");
    }
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=n;i>0;i--){
        ud(a[i],1,1);
        for(int j=2;j<=k;j++)
            ud(a[i],j,qr(a[i]-1,j-1));
    }
    printf("%d\n",qr(n,k));
    return 0;
}
