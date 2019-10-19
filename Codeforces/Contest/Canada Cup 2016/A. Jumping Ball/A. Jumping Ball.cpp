#include<cstdio>
int n,cnt=0;
char a[200002];
int main(){
    scanf("%d %s",&n,a);
    for(int i=0;a[i]=='<';i++)
        cnt++;
    for(int i=n-1;a[i]=='>';i--)
        cnt++;
    printf("%d\n",cnt);
    return 0;
}
