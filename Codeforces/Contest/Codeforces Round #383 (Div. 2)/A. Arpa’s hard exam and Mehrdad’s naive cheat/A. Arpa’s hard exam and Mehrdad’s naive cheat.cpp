#include<cstdio>
int n;
int main(){
    scanf("%d",&n);
    if(n==0){
        printf("1\n");
        return 0;
    }
    n%=4;
    if(n==1)    printf("8\n");
    if(n==2)    printf("4\n");
    if(n==3)    printf("2\n");
    if(n==0)    printf("6\n");
    return 0;
}
