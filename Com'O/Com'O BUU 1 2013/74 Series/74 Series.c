#include<stdio.h>
int main(){
    int q,n,i,j,sum[50],chk;
    sum[0]=0;
    for(i=1;i<=45;i++)
        sum[i]=sum[i-1]+i;
    scanf("%d",&q);
    while(q--){
        chk=1;
        scanf("%d",&n);
        for(i=0;i<=44;i++){
            for(j=i+1;j<=45&&chk;j++){
                if(sum[j]-sum[i]==n){
                    if(i+1==j)  break;
                    printf("%d %d\n",i+1,j);
                    chk=0;
                    break;
                }
            }
        }
        if(chk)     printf("-1\n");
    }
    return 0;
}
