#include<cstdio>
int n,ans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j*j<=i;j++)
            if(i%j==0)  cnt++;
        ans+=cnt;
    }
    printf("%d\n",ans);
    return 0;
}
