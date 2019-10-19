#include<cstdio>
int n,a[100002],x,y;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&x,&y);
        printf("%d\n",a[y]-a[x-1]);
    }
    return 0;
}
