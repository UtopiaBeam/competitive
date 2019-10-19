#include<cstdio>
int n,x,cnt=0;
int main(){
    scanf("%d %d",&n,&x);
    for(int i=1;i<=n;i++)
        if(x%i==0 && 1<=x/i && x/i<=n)   cnt++;
    printf("%d\n",cnt);
    return 0;
}
