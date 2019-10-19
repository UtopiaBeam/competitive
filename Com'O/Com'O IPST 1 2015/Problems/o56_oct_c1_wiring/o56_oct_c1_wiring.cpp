#include<cstdio>
int t,n,a[100002],b[100002];
int find(int x){
    if(x!=b[x])     return b[x]=find(b[x]);
    return b[x];
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i])    b[a[i]]=i;
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i])    a[i]=b[a[i]];
        }
        for(int i=1;i<=n;i++)   b[i]=i;
        for(int i=1;i<=n;i++){
            if(a[i] && a[i]!=i){
                int r1=find(i),r2=find(a[i]);
                if(r1==r2){
                    printf("NO\n");     break;
                }
                b[r1]=r2;
            }
            if(i==n){
                printf("YES\n");
            }
        }
    }
    return 0;
}
