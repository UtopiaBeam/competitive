#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char name;  int scr;
}SCR;
SCR a[10];
char b[10010];
int n=7;
int cmp(const void *a,const void *b){
    SCR *aa=(SCR *)a,*bb=(SCR *)b;
    if(aa->scr!=bb->scr)    return bb->scr - aa->scr;
    return aa->name - bb->name;
}
int main(){
    int len,i,in,min,chk;
    for(i=0;i<7;i++)
        a[i].name=i+'A',a[i].scr=0;
    while(1){
        scanf(" %s",b);
        if(!strcmp(b,"!")){
            qsort(a,7,sizeof(SCR),cmp);
            printf("%d\n",n);
            for(i=0;i<n;i++)
                printf("%c %d\n",a[i].name,a[i].scr);
            return 0;
        }
        len=strlen(b);
        for(i=0;i<len;i++)
            if(a[b[i]-'A'].scr>=0)
                a[b[i]-'A'].scr++;
        min=1<<20,chk=1;
        for(i=0;i<7;i++)
            if(a[i].scr<min && a[i].scr>=0)
                in=i,min=a[i].scr;
        for(i=0;i<7;i++)
            if(i!=in && a[i].scr==min)
                chk=0;
        if(chk&&n>1)     a[in].scr=-1,n--;
    }
}
