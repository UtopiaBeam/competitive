#include<stdio.h>
int main(){
    int ans,n;
    scanf("%d",&n);
    ans=n;
    while(--n){
        ans*=n;
    }
    printf("%d\n",ans);
    return 0;
}
