#include<stdio.h>
#include<string.h>
char a[110];
int main(){
    int len,chk1=0,chk2=0,chk3=0,i;
    scanf(" %s",a);
    len=strlen(a);
    for(i=0;i<len;i++){
        if(a[i]=='(')   chk1++;
        if(a[i]==')')   chk1--;
        if(a[i]=='[')   chk2++;
        if(a[i]==']')   chk2--;
        if(a[i]=='{')   chk3++;
        if(a[i]=='}')   chk3--;
    }
    if(chk1)    printf("'(' is used incorrectly.\n");
    if(chk2)    printf("'[' is used incorrectly.\n");
    if(chk3)    printf("'{' is used incorrectly.\n");
    if(!chk1 && !chk2 && !chk3)
        printf("All correct.\n");
    return 0;
}
