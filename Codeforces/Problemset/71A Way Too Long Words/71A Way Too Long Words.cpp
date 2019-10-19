#include<cstdio>
#include<cstring>
int n;
char a[105];
int main(){
    scanf("%d",&n);
    while(n--){
        scanf(" %s",a);
        if(strlen(a)>10)    printf("%c%d%c\n",a[0],strlen(a)-2,a[strlen(a)-1]);
        else    printf("%s\n",a);
    }
    return 0;
}
