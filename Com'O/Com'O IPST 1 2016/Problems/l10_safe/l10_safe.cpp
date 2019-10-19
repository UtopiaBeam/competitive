#include<cstdio>
int mn=1<<30,n,x,v;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&x,&v);
        if(v>mn)    printf("%d\n",v-mn);
        else{
            printf("0\n");
            mn=v;
        }
    }
    return 0;
}
