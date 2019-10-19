#include<cstdio>
int n,m,x,y,cnt=0;
int main(){
    scanf("%d %d",&n,&m);
    while(n--){
        for(int i=0;i<m;i++){
            scanf("%d %d",&x,&y);
            cnt+=x||y;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
