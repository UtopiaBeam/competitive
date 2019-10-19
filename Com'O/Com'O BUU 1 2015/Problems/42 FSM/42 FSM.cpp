#include<cstdio>
#include<cstring>
char a[102];
int len;
int main(){
    scanf(" %s",a);
    int len=strlen(a);
    printf("%d ",len);
    if(len==1)  printf("Reject\n");
    else{
        for(int i=1;i<len;i++)
            if(a[i]+a[i-1]-2*'0'!=1){
                printf("Reject\n");   return 0;
            }
        printf("Accept\n");
    }
    return 0;
}
