#include<stdio.h>
#include<string.h>
int main(){
    int lena,lenb,i,chk,len,t;
    char a[5050],b[5050];
    scanf(" %s %s",a,b);
    lena=strlen(a),lenb=strlen(b);
    chk=1;
    if(a[0]=='-'){ strcpy(a,&a[1])  lena--,chk=-1; }
    for(i=0;i<lena;i++)     a[i]=(a[i]-'0')*chk;
    for(i=0;i<lena;i++)     t=a[i],a[i]=a[lena-1-i],a[lena-1-i]=t;
    chk=1;
    if(b[0]=='-'){ strcpy(b,&b[1])  lenb--,chk=-1; }
    for(i=0;i<lenb;i++)     b[i]=(b[i]-'0')*chk;
    for(i=0;i<lenb;i++)     t=b[i],b[i]=b[lenb-1-i],b[lenb-1-i]=t;
    if()
}
