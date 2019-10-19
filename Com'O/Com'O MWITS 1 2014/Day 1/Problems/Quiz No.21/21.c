#include<stdio.h>
int main(){
    int n,i,cnt=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        if(n%i==0)  printf("%d ",i);
        cnt++;
    }
    printf("\n%d\n",cnt);
    return 0;
}
