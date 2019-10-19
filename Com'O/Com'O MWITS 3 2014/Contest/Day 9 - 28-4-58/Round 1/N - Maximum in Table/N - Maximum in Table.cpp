#include<cstdio>
int a[15],n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        a[i]=1;
    for(int i=1;i<n;i++){
        for(int j=2;j<=n;j++)
            a[j]+=a[j-1];
    }
    printf("%d\n",a[n]);
    return 0;
}
