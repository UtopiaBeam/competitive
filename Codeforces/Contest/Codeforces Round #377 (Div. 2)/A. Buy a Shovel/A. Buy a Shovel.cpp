#include<cstdio>
int n,m;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;;i++){
        if((n*i)%10==0 || (n*i)%10==m){
            printf("%d\n",i);
            return 0;
        }
    }
}
