#include<stdio.h>
#include<string.h>
char a[5010],b[5010];
int main(){
    int lena,lenb,chk,i;
    scanf(" %s %s",a,b);
    lena=strlen(a);  lenb=strlen(b);
    chk=1;
    if(a[0]=='-'){
        for(i=1;i<lena;i++)
            strcpy(a,&a[1]);
        lena--,chk=-1;
    }
    for(i=0;i<lena;i++)  a[i]=(a[i]-'0')*chk;
    chk=-1;
    if(b[0]=='-'){
        for(i=1;i<lenb;i++)
            strcpy(b,&b[1]);
        lenb--,chk=1;
    }
    for(i=0;i<lena;i++)  b[i]=(b[i]-'0')*chk;

}
