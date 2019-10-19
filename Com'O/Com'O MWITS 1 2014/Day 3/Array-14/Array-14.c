#include<stdio.h>
#include<string.h>
int len,mid,chk=1;
char a[220];
int main(){
    int i;
    scanf(" %s",a);
    len=strlen(a),mid=len/2;
    for(i=0;i<mid;i++)
        if(a[i]!=a[len-i-1]){
            printf("No\n");
            return 0;
        }
    printf("Yes\n");
    return 0;
}
