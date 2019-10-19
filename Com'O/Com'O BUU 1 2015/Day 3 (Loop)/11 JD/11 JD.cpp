#include<cstdio>
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<2*n;i++){
        for(int j=1;j<n-i/2;j++)  printf("-");
        for(int j=0;j<i/2*2+3;j++)
            printf("%c",(i%2 && j%2)? '-':'*');
        for(int j=1;j<n-i/2;j++)  printf("-");
        printf("\n");
    }
    for(int i=0;i<2*n+1;i++)  printf("*");
    return 0;
}
