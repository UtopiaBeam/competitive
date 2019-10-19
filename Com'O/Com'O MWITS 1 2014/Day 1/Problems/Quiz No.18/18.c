#include<stdio.h>
int a[10010]={0,0,1},p[5010];
int main(){
    int n,i,j,k,cnt=0;
    scanf("%d",&n);
    for(i=3;i<=n;i+=2)
        a[i]=1;
    for(i=3;i*i<=n;i++){
        if(a[i]){
            for(j=i*i;j<=n;j+=i)
                a[j]=0;
        }
    }
    for(i=2;i<=n;i++){
        if(a[i]){
            printf("%d ",i);
            cnt++;
        }
    }
    printf("\n%d\n",cnt);
    return 0;
}
