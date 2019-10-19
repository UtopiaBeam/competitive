#include<cstdio>
#include<cstring>
char a[1005];
int k,len;
int main(){
    scanf(" %s %d",a,&k);
    if(strlen(a)%k){
        printf("NO\n");     return 0;
    }
    len=strlen(a)/k;
    for(int i=0;i<k;i++)
        for(int j=0;j<len/2;j++)
            if(a[len*i+j]!=a[len*(i+1)-1-j]){
                printf("NO\n");     return 0;
            }
    printf("YES\n");
    return 0;
}
