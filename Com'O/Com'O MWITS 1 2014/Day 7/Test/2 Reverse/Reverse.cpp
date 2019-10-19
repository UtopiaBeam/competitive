#include<stdio.h>
#include<string.h>
char a[1005][1005];
int main(){
    freopen("reverse.in","r",stdin);
    freopen("reverse.out","w",stdout);
    int i,j,in=0;
    while(scanf(" %s",a[in])!=EOF){
        if(a[in][strlen(a[in])-1]=='.'){
            for(i=0;i<strlen(a[in])-1;i++)
                printf("%c",a[in][i]);
            printf(" ");
            for(i=in-1;i>=0;i--){
                printf("%s",a[i]);
                if(i!=0)    printf(" ");
            }
            printf(".\n");  in=0;
        }
        else    in++;
    }
    return 0;
}
