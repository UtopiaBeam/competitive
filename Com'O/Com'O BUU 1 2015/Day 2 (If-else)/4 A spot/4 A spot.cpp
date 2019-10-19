/*
TASK: A spot
AUTHOR: Natchapol Srisang
SCHOOL: Mahidolwittayanusorn School
LANG: C
*/
#include<cstdio>
int main(){
    int x1,y1,x2,y2,x3,y3,x,y;
    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
    if(x1==x2)  x=x3;
    else if(x2==x3) x=x1;
    else    x=x2;
    if(y1==y2)  y=y3;
    else if(y2==y3) y=y1;
    else    y=y2;
    printf("%d %d\n",x,y);
    return 0;
}
