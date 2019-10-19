#include<cstdio>
int t,n,m;
int gcd(int x,int y){
    if(x%y)     return gcd(y,x%y);
    return y;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        int GCD=gcd(m,n);
        if(GCD==1)      printf("Yes\n");
        else    printf("No %d\n",n/GCD);
    }
    return 0;
}
