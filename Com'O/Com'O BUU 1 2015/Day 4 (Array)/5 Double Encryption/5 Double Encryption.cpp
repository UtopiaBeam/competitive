#include<cstdio>
int n,k,p;
char a[102];
int main(){
    scanf("%d %d %d %s",&n,&k,&p,a);
    for(int i=0;i<k;i++)
        for(int j=i;j<n;j+=k)
            printf("%c",a[j]);
    printf("\n");
    for(int i=0;i<k;i++)
        for(int j=i;j<n;j+=k){
            if(a[j]>='a' && a[j]<='z')  printf("%c",(a[j]-'a'+26+p)%26+'a');
            else    printf("%c",(a[j]-'A'+26+p)%26+'A');
        }
    return 0;
}
