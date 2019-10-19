#include<cstdio>
long long k;
int n,x;
int bs(int s,int e){
    if(s==e)    return s;
    int t=(s+e)/2;
    if((t+1)*(n+t)>k)   return bs(s,t);
    if(n*(t+1)*(t+1)<k)     return bs(t+1,e);
}
int main(){
    scanf("%d %lld",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&x);
    printf("%d\n",bs(0,(int)1e7));
    return 0;
}
