#include<cstdio>
int cnt=0,n,nw=1;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++,nw++){
        if(nw%7==6 || nw%7==0)
            cnt++;
    }
    printf("%d ",cnt);
    cnt=0,nw=6;
    for(int i=1;i<=n;i++,nw++){
        if(nw%7==6 || nw%7==0)
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
