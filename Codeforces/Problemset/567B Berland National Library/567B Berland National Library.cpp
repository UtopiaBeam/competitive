#include<cstdio>
int n,t,cnt=0,mx=0,a[1000005];
char ch;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf(" %c %d",&ch,&t);
        if(ch=='+')     cnt++,a[t]=1;
        else if(a[t])   cnt--,a[t]=0;
        else    mx++;
        if(mx<cnt)      mx=cnt;
    }
    printf("%d\n",mx);
    return 0;
}
