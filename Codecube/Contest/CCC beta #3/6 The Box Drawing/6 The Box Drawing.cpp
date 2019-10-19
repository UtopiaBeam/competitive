#include<cstdio>
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<=2*n;i++) printf("- ");
    printf("\n");
    for(int i=1;i<n-1;i++){
        for(int j=0;j<n-i;j++)  printf("- ");
        for(int j=0;j<=2*i;j++) printf("# ");
        for(int j=0;j<n-i;j++)  printf("- ");
        printf("\n");
    }
    for(int i=1;i<n;i++){
        printf("- ");
        for(int j=0;j<i;j++)    printf("# ");
        printf("- ");
        for(int j=0;j<2*n-3-2*i;j++)    printf("# ");
        if(i<n-1)  printf("- ");
        for(int j=0;j<i;j++)    printf("# ");
        printf("-\n");
    }
    for(int i=1;i<n-1;i++){
        for(int j=0;j<i;j++)    printf("- ");
        for(int j=0;j<n-i;j++)    printf("# ");
        printf("- ");
        for(int j=0;j<n-i;j++)    printf("# ");
        for(int j=0;j<i;j++)    printf("- ");
        printf("\n");
    }
    for(int i=0;i<=2*n;i++) printf("- ");
    return 0;
}
