#include<cstdio>
int a[1005][1005],n,x,y,cnt=0;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&x,&y);
        if(!a[x][y])    a[x][y]=1,cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
