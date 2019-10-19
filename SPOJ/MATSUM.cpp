#include<cstdio>
#include<cstring>
int t,n,ft[1030][1030],sx,sy,ex,ey,v;
char cmd[5];
void upd(int x,int y,int v){
    for(int i=x;i<=n;i+=-i&i)
        for(int j=y;j<=n;j+=-j&j)
            ft[i][j]+=v;
}
int getx(int x,int y){
    int sum=0;
    for(int i=x;i;i-=-i&i)
        for(int j=y;j;j-=-j&j)
            sum+=ft[i][j];
    return sum;
}
int get(int sx,int sy,int ex,int ey){
    return getx(ex,ey)-getx(sx-1,ey)-getx(ex,sy-1)+getx(sx-1,sy-1);
}
int main(){
    scanf("%d",&t);
    while(t--){
        memset(ft,0,sizeof(ft));
        scanf("%d",&n);
        while(scanf(" %s",cmd) && strcmp(cmd,"END")){
            if(!strcmp(cmd,"SET")){
                scanf("%d %d %d",&sx,&sy,&v);
                sx++;   sy++;
                upd(sx,sy,v-get(sx,sy,sx,sy));
            }
            else if(!strcmp(cmd,"SUM")){
                scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
                sx++;   sy++;   ex++;   ey++;
                printf("%d\n",get(sx,sy,ex,ey));
            }
        }
    }
    return 0;
}
