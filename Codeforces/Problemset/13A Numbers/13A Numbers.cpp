#include<cstdio>
int n,ans=0;
int gcd(int x,int y){
    if(y==0)    return x;
    if(x%y)     return gcd(y,x%y);
    return y;
}
int main(){
    scanf("%d",&n);
    for(int i=2;i<n;i++){
        int t=0,t2=n;
        while(t2)
            t+=t2%i,t2/=i;
        ans+=t;
    }
    printf("%d/%d\n",ans/gcd(n-2,ans),(n-2)/gcd(n-2,ans));
    return 0;
}
