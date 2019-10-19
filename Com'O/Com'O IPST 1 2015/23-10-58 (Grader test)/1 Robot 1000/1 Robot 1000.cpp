#include<cstdio>
int x=0,y=0;
char a[102];
int main(){
    scanf(" %s",a);
    for(int i=0;a[i];i++){
        if(a[i]=='N')   y++;
        else if(a[i]=='E')  x++;
        else if(a[i]=='S')  y--;
        else if(a[i]=='W')  x--;
        else    x=y=0;
    }
    printf("%d %d\n",x,y);
    return 0;
}
