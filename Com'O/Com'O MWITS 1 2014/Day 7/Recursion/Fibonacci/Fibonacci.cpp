#include<stdio.h>
int f(int n){
    if(n<2) return n;
    return f(n-1)+f(n-2);
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",f(n));
    return 0;
}
