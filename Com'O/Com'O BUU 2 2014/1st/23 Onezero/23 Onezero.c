#include<stdio.h>
long long sum,k;
int main(){
    int q,i,chk;
    scanf("%d",&q);
    while(q--){
        sum=0,chk=1;
        scanf("%I64d",&k);
        for(i=0;i<44725;i++){
            sum+=i;
            if(sum==k-1){
                printf("1\n");  chk=0;
                continue;
            }
        }
        if(chk)     printf("0\n");
    }
    return 0;
}
