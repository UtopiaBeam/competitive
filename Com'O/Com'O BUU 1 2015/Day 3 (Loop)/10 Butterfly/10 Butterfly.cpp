#include<cstdio>
int n;
char c;
int main(){
    scanf(" %c %d",&c,&n);
    for(int i=1;i<=n/2;i++){
        for(int j=0;j<i;j++)   printf("%c",c);
        for(int j=0;j<n-2*i;j++)    printf(".");
        for(int j=0;j<i;j++)    printf("%c",c);
        printf("\n");
    }
    for(int i=n/2-1;i>0;i--){
        for(int j=0;j<i;j++)   printf("%c",c);
        for(int j=0;j<n-2*i;j++)    printf(".");
        for(int j=0;j<i;j++)    printf("%c",c);
        printf("\n");
    }
    return 0;
}
