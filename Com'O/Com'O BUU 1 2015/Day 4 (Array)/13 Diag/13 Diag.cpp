#include<cstdio>
int r,c,a[502][502],x,y,cnt,k;
int main(){
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            scanf("%d",&a[i][j]);
    x=r,y=1,k=0,cnt=0;
    while(++cnt<=r*c){
        printf("%d ",a[x][y]);
        x++,y++;
        if(x>r || y>c)  x=r-(++k),y=1;
        while(x<1 || y<1)   x++,y++;
    }
    printf("\n");
    x=1,y=1,k=1,cnt=0;
    while(++cnt<=r*c){
        printf("%d ",a[x][y]);
        x--,y++;
        if(x<1 || y>c)  x=++k,y=1;
        while(x>r)  x--,y++;
    }
    return 0;
}
