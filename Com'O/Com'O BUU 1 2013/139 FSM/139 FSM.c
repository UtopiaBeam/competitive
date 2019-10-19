#include<stdio.h>
#include<string.h>
int main(){
    int len,i,chk=1,next;
    char str[120];
    gets(str);
    len=strlen(str);
    printf("%d ",len);
    if(len==1)  chk=0;
    for(i=0;i<len;i++)
        str[i]-='0';
    next=1-str[0];
    for(i=1;i<len&&chk;i++){
        if(str[i]==next)
            next=1-next;
        else   chk=0;
    }
    if(chk)     printf("Accept\n");
    else        printf("Reject\n");
    return 0;
}
