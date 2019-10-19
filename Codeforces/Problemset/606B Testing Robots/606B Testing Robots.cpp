#include<cstdio>
int r,c,x,y,b[502][502];
char a[100002];
int main(){
    scanf("%d %d %d %d %s",&r,&c,&x,&y,a);
    printf("1 ");
    for(int i=0;a[i];i++){
        b[x][y]=1;
        if(a[i]=='U')   x--;
        if(a[i]=='D')   x++;
        if(a[i]=='L')   y--;
        if(a[i]=='R')   y++;
        if(x<1)         x=1;
        else if(x>r)    x=r;
        else if(y<1)    y=1;
        else if(y>c)    y=c;
        if(a[i+1]){
            if(b[x][y])     printf("0 ");
            else    printf("1 ");
        }
    }
    int cnt=r*c;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            cnt-=b[i][j];
    printf("%d\n",cnt);
    return 0;
}
