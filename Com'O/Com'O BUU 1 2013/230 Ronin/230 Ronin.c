#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char str[20],fin[20],code[1020];
    int i,j,lenstr,lenfin,lencode;
    int I[1000],J[1000],cnt=0;
    gets(str),gets(fin),gets(code);
    lenstr=strlen(str),lenfin=strlen(fin),lencode=strlen(code);
    for(i=0;i<lenstr;i++)
        if(isupper(str[i]))     str[i]-='A'-'a';
    for(i=0;i<lenfin;i++)
        if(isupper(fin[i]))     fin[i]-='A'-'a';
    for(i=0;i<lencode;i++)
        if(isupper(code[i]))    code[i]-='A'-'a';
    for(i=0;i<=lencode-lenstr;i++)
        if(!strncmp(str,&code[i],lenstr))
            for(j=i;j<lencode-lenfin;j++)
                if(!strncmp(fin,&code[j],lenfin)){
                    I[cnt]=i+1,J[cnt]=j+lenfin,cnt++;
                    i=j;
                    break;
                }
    printf("%d\n",cnt);
    for(i=0;i<cnt;i++)
        printf("%d %d\n",I[i],J[i]);
    return 0;
}
