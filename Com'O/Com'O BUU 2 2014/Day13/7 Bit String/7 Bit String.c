#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char str[1000010],a[10];
int n,len,ans[200010];
int cmp(const void *a,const void *b){
    return *(int *)a - *(int *)b;
}
int bit(char code[]){
    int key=0,i;
    for(i=0;i<n;i++){
        code[i]-='0';
        key+=(int)pow(2,n-1-i)*code[i];
    }
    return key;
}
int main(){
    int i,j=0;
    scanf("%d %s",&n,str);
    len=strlen(str);
    for(i=0;i<len;i+=n){
        if(len-i>=n){
            strncpy(a,&str[i],n);
            //printf("%s ",a);
            ans[j++]=bit(a);
        }
    }
    qsort(ans,j,sizeof(int),cmp);
    for(i=0;i<j;i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
