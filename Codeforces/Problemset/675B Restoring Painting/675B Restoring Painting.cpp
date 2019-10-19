#include<cstdio>
int n,a,b,c,d;
long long ans=0;
int main(){
    scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
    for(int x=1;x<=n;x++){
        int y=x-b+c;
        int z=x+a-d;
        int w=a+y-d;
        if(1<=y && y<=n && 1<=z && z<=n && 1<=w && w<=n)
            ans++;
    }
    printf("%I64d\n",ans*n);
    return 0;
}
