#include<stdio.h>
#include<string.h>
char dir[5]="NESW",cmd[5];
int now=1,n,k,x=0,y=0;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf(" %s %d",cmd,&k);
        if(cmd[0]=='B')   now+=2;
        else if(cmd[0]=='L')  now+=3;
        else if(cmd[0]=='R')  now++;
        now%=4;
        if(now==0)  y+=k;
        else if(now==1) x+=k;
        else if(now==2) y-=k;
        else if(now==3) x-=k;
        if(x<=-50000||x>=50000||y<=-50000||y>=50000){
            printf("DEAD\n");
            return 0;
        }
    }
    printf("%d %d\n%c\n",x,y,dir[now]);
    return 0;
}
