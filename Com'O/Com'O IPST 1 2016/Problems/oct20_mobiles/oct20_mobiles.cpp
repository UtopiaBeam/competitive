#include<cstdio>
int t,n,sx,sy,ex,ey,v,ft[1030][1030];
void upd(int x,int y,int v){
    for(int i=x;i<=n;i+=-i&i)
        for(int j=y;j<=n;j+=-j&j)
            ft[i][j]+=v;
}
int get(int x,int y){
    int sum=0;
    for(int i=x;i;i-=-i&i)
        for(int j=y;j;j-=-j&j)
            sum+=ft[i][j];
    return sum;
}
int sum(int sx,int sy,int ex,int ey){
    return get(ex,ey)-get(sx-1,ey)-get(ex,sy-1)+get(sx-1,sy-1);
}
int main(){
    while(scanf("%d",&t) && t!=3){
        if(t==0)    scanf("%d",&n);
        if(t==1){
            scanf("%d %d %d",&sx,&sy,&v);
            upd(sx+1,sy+1,v);
        }
        if(t==2){
            scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
            printf("%d\n",sum(sx+1,sy+1,ex+1,ey+1));
        }
    }
    return 0;
}
