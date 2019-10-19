#include<cstdio>
int t,n,a[100002],r[100002];
int fr(int x){
    if(x!=r[x])     r[x]=fr(r[x]);
    return r[x];
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            r[a[i]]=i;
        }
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            a[i]=(a[i]!=0)*r[a[i]];
        }
        for(int i=1;i<=n;i++)
            r[i]=i;
        for(int i=1;i<=n;i++){
            if(a[i]!=0 && a[i]!=i){
                int rx=fr(a[i]),ry=fr(i);
                if(rx==ry){
                    printf("NO\n");
                    break;
                }
                r[rx]=ry;
            }
            if(i==n)    printf("YES\n");
        }
    }
}
