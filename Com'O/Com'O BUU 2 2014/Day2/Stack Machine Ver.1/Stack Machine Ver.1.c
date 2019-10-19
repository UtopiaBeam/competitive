/*
TASK: Stack
LANG: C
AUTHOR: Natchapol Srisang
School: PccChon
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char VarN[100][10],VarL[100];
int stack[200],top=0;
int main(){
    char s[50],ch[10];
    int n,i=0;
    scanf("%d",&n);
    while(n--){
        scanf(" %s",s);
        if(!strcmp(s,"assign")){
            scanf(" %s %d",VarN[i],VarL[i]);
            i++;
        }
        if(!strcmp(s,"pushStack")){
            scanf(" %s",ch);
            if(is)
        }
    }
}
