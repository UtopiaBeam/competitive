#include<stdio.h>
int cnt[30];
char a[110];
int main(){
    int n;
    scanf("%d %s",&n,a);
    for(int i=0;i<n;i++){
        if('A'<=a[i] && a[i]<='Z')    a[i]-='A'-'a';
        cnt[a[i]-'a']=1;
    }
    for(int i=0;i<26;i++)
        if(!cnt[i]){
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    return 0;
}
