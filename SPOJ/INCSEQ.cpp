#include<cstdio>
int ft[52][100000],n,k,t;
void ud(int i,int x,int v){
    for(;x<100000;x+=-x&x)  ft[i][x]=(ft[i][x]+v)%5000000;
}
int gs(int i,int x){
    int sum=0;
    for(;x>0;x-=-x&x)     sum=(sum+ft[i][x])%5000000;
    return sum;
}
int main(){
    scanf("%d %d",&n,&k);
    while(n--){
        scanf("%d",&t);
        t++;
        ud(1,t,1);
        for(int i=2;i<=k;i++)
            ud(i,t,gs(i-1,t-1));
    }
    printf("%d\n",gs(k,99999));
    return 0;
}
