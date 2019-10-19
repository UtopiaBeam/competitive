#include<cstdio>
int n,k;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n-1;i++){
        for(int j=1;j<n-i;j++)  printf("-");
        for(int l=0;l<k;l++){
            if(i)   printf("*");
            for(int j=0;j<2*i-1;j++)    printf("+");
            if(i<n-2)   printf("*");
            if(l<k-1)   for(int j=2;j<2*n-2*i-3;j++)  printf("-");
        }
        if(i==n-2)   printf("*");
        for(int j=1;j<n-i;j++)  printf("-");
        printf("\n");
    }
    printf("*");
    for(int i=0;i<2*n-5;i++)    printf("+");
    for(int i=1;i<k;i++){
        printf("*#*");
        for(int j=0;j<2*n-7;j++)  printf("+");
    }
    printf("++*\n");
    for(int i=n-2;i>=0;i--){
        for(int j=1;j<n-i;j++)  printf("-");
        for(int l=0;l<k;l++){
            if(i)   printf("*");
            for(int j=0;j<2*i-1;j++)    printf("+");
            if(i<n-2)   printf("*");
            if(l<k-1)   for(int j=2;j<2*n-2*i-3;j++)  printf("-");
        }
        if(i==n-2)   printf("*");
        for(int j=1;j<n-i;j++)  printf("-");
        printf("\n");
    }
}
