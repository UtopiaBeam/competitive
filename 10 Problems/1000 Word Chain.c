#include<stdio.h>
#include<string.h>
int main(){
    char a[1010],b[1010];
    int len,n,i,chk;
    scanf("%d %d %s",&len,&n,a);
    if(n==1){
        printf("%s\n",a);
        return 0;
    }
    while(--n){
        chk=0;
        scanf(" %s",b);
        for(i=0;i<len;i++){
            if(a[i]!=b[i]){
                chk++;
                if(chk>2){
                    printf("%s\n",a);
                    return 0;
                }
            }
        }
        strcpy(a,b);
    }
    printf("%s\n",b);
    return 0;
}
