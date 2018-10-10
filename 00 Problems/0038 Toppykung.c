#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char a[150];
}str;
str s[1010];
int cmp(const void *a,const void *b){
    str *x,*y;
    x=(str *)a,y=(str *)b;
    return strcmp(x->a,y->a);
}
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %s",s[i].a);
        for(j=0;j<i;j++)
            if(!strcmp(s[i].a,s[j].a))
                i--,n--;
    }
    qsort(s,n,sizeof(s[0]),cmp);
    for(i=0;i<n;i++)
        printf("%s\n",s[i].a);
    return 0;
}
