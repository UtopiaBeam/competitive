#include<stdio.h>
int n;
void fractal(int a,int b){
    if(a==1){
        for(int i=0;i<b;i++)
            printf(" ");
        printf("*");
        return ;
    }
    fractal(a/2,b);
    for(int i=0;i<n-a/2-b;i++)
        printf(" ");
    printf("\n");
    for(int i=0;i<b;i++)
        printf(" ");
    for(int i=0;i<a;i++)
        printf("*");
    for(int i=0;i<n-a-b;i++)
        printf(" ");
    printf("\n");
    fractal(a/2,a/2+b);
}
int main(){
    scanf("%d",&n);
    fractal(n,0);
}
