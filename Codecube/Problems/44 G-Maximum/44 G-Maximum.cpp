#include<cstdio>
int n,a[1000002],l[1000002],r[1000002];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)    scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        l[i]=i-1;
        while(l[i]>0 && a[i]>=a[l[i]])  l[i]=l[l[i]];
    }
    for(int i=n;i>0;i--){
        r[i]=i+1;
        while(r[i]<=n && a[i]>=a[r[i]])  r[i]=r[r[i]];
    }
    for(int i=1;i<=n;i++)    printf("%d ",r[i]-l[i]-1);
    return 0;
}
