#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n<=600)  printf("300\n");
    else        printf("%.2lf\n",300+1.50*(n-600));
    return 0;
}
