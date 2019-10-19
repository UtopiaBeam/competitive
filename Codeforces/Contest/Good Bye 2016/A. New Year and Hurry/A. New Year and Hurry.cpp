#include<cstdio>
int n,m;
int main(){
    scanf("%d %d",&n,&m);
    m=240-m;
    int cnt=1;
    while(cnt<=n){
        m-=5*cnt;
        if(m<0)     cnt--;
        if(m<=0 || cnt==n)    break;
        cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
