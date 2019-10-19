#include<cstdio>
int n,m,l,f[15]={1},pre=1;
int c(int n,int k){
    return f[n]/(f[k]*f[n-k]);
}
int main(){
    scanf("%d %d %d",&n,&m,&l);
    for(int i=1;i<=n;i++)   f[i]=f[i-1]*i;
    for(int i=1;i<=m;i++){
        while(l>c(n-pre,m-i))     l-=c(n-pre,m-i),pre++;
        printf("%d ",pre++);
    }
    return 0;
}
