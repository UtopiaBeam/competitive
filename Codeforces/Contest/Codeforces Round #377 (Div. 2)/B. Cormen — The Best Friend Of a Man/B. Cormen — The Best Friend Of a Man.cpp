#include<cstdio>
int n,k,a[502],cnt=0;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<n-1;i++){
        if(a[i]+a[i+1]<k){
            cnt+=k-(a[i+1]+a[i]);
            a[i+1]+=k-(a[i+1]+a[i]);
        }
    }
    printf("%d\n",cnt);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
