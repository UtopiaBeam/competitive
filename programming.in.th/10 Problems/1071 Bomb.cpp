#include<cstdio>
int a[1005][1005],n,m,x,y,r;
int main(){
    scanf("%d %d",&n,&m);
    while(n--){
        scanf("%d %d",&x,&y);
        a[x][y]=1;
    }
    while(m--){
        int cnt=0;
        scanf("%d %d %d",&x,&y,&r);
        for(int i=x-r;i<=x+r;i++){
            if(i<0 || i>1000)   continue;
            for(int j=y-r;j<=y+r;j++){
                if(j<0 || j>1000)   continue;
                if(a[i][j])     a[i][j]=0,cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
