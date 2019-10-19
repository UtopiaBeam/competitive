#include<cstdio>
int n,m,p;
int main(){
    while(scanf("%d",&n) && n){
        scanf("%d %d",&m,&p);
        if(n+p<2*m+1)     printf("yes\n");
        else    printf("no\n");
    }
    return 0;
}
