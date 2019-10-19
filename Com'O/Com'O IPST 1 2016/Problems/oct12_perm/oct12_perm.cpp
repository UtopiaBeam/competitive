#include<cstdio>
int n,m,l,a[15],f[15]={1};
int p(int n,int k){
    return f[n]/f[n-k];
}
int main(){
    scanf("%d %d %d",&n,&m,&l);
    for(int i=1;i<=n;i++)   f[i]=f[i-1]*i;
    for(int i=1;i<=m;i++){
        int t=l/p(n-i,m-i)+(l%p(n-i,m-i)>0);
//        printf("%d ",t);
        for(int j=1;j<=n;j++){
            if(!a[j])    t--;
            if(!t){
                a[j]=1;
                printf("%d ",j);    break;
            }
        }
        l=(l-1)%p(n-i,m-i)+1;
    }
    return 0;
}
