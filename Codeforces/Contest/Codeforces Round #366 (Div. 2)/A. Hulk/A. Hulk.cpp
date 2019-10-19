#include<cstdio>
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(i%2)     printf("I hate ");
        else        printf("I love ");
        if(i<n)     printf("that ");
        else        printf("it\n");
    }
    return 0;
}
