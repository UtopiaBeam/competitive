#include<cstdio>
char a[5][5];
int main(){
    for(int i=0;i<3;i++)
        scanf(" %s",a[i]);
    for(int i=0;i<9;i++){
        int j=8-i;
        if(a[i/3][i%3]!=a[j/3][j%3]){
            printf("NO\n");     return 0;
        }
    }
    printf("YES\n");
    return 0;
}
