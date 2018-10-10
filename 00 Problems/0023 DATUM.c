#include<stdio.h>
int main(){
    int d,m,i,r=3,month[13]={0,0,31,28,31,30,31,30,31,31,30,31,30};
    char day[8][15]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    scanf("%d %d",&d,&m);
    r+=d;
    for(i=1;i<=m;i++)
        r+=month[i];
    printf("%s\n",day[r%7]);
    return 0;
}
