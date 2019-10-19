#include<cstdio>
int n,t,chk=1;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&t);
        if(t==1)    chk=-1;
    }
    printf("%d\n",chk);
    return 0;
}
