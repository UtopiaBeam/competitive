#include<stdio.h>
int main(){
    int n,a,b,c,d,e,ans=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
        ans+=8*a+6*b+4*c+2*d+e;
    }
    printf("%d\n",ans/8+(ans%8>0));
    return 0;
}
