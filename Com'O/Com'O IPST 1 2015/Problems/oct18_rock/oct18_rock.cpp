#include<cstdio>
int n,a[102],dp[102][102];
void input(int i){
    if(i==2*n)    return ;
    scanf("%d",&a[i]);
    dp[i][i]=a[i];
    input(i+1);
}
int max(int x,int y){
    return x>y? x:y;
}
int f(int s,int e){
    if(s>e)     return 0;
    if(dp[s][e])    return dp[s][e];
    if(s==e)    return dp[s][e];
    return dp[s][e]=max(a[s]+max(f(s+2,e),f(s+1,e-1)),a[e]+max(f(s,e-2),f(s+1,e-1)));
}
int main(){
    scanf("%d",&n);
    input(0);
    printf("%d\n",f(0,2*n-1));
    return 0;
}
