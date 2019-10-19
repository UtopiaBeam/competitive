#include<cstdio>
int q,n;
int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=0;;i++){
            if(n==(i*(i+1))/2+1){
                printf("1\n");      break;
            }
            if(n<(i*(i+1))/2+1){
                printf("0\n");      break;
            }
        }
    }
    return 0;
}
