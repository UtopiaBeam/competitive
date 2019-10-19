#include<cstdio>
int q,g,k;
int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&g,&k);
        printf("%d\n",(g-100)/(10+100*(k-1))+((g-100)%(10+100*(k-1)>0)));
    }
    return 0;
}
