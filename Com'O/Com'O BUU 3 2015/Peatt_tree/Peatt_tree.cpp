#include<cstdio>
int q,n,c[1002]={0,1};
int main(){
    for(int i=2;i<=1000;i++)
        for(int j=1;j<i;j++){
            c[i]+=c[j]*c[i-j];
            c[i]%=9973;
        }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        printf("%d\n",c[n]);
    }
    return 0;
}
