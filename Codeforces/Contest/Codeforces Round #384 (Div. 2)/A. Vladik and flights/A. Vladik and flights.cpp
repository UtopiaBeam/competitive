#include<cstdio>
int n,a,b,c[100002];
char s[100002];
int main(){
    scanf("%d %d %d %s",&n,&a,&b,s);
    for(int i=0;i<n;i++)
        c[i+1]=s[i];
    printf("%d\n",c[a]^c[b]);
    return 0;
}
