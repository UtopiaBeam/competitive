#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            if(i+j>=n-1)  printf("* ");
            else    printf(" ");
        printf("\n");
    }
    for(i=n-2;i>=0;i--){
        for(j=0;j<n;j++)
            if(i+j>=n-1)  printf("* ");
            else    printf(" ");
        printf("\n");
    }
    getch();    system("cls");
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++)  printf("  ");
        for(j=n-i;j<2*n-i;j++)  printf("* ");
        for(j=2*n-i+1;j<2*n;j++)    printf("  ");
        printf("\n");
    }
    return 0;
}
