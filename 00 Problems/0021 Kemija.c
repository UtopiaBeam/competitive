#include<stdio.h>
#include<string.h>
int main(){
    char a[120],b[5]={'a','e','i','o','u'};
    int i,j,len;
    gets(a);
    len=strlen(a);
    for(i=0;i<len-2;i++){
        for(j=0;j<5;j++){
            if(a[i]==b[j] && a[i]==a[i+2] && a[i+1]=='p'){
                strcpy(&a[i+1],&a[i+3]);
                len-=2;
            }
        }
    }
    printf("%s\n",a);
    return 0;
}
