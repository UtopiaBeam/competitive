/*
TASK: Route
AUTHOR: Natchapol Srisang
SCHOOL: Mahidolwittayanusorn School
LANG: C
*/
#include<cstdio>
int min(int x,int y){
    return x<y? x:y;
}
int abs(int x){
    return x>0? x:-x;
}
int main(){
    int a,b,x,y;
    scanf("%d %d %d %d",&x,&y,&a,&b);
    if(2*a<=b)    printf("%d\n",a*(x+y));
    else if(a<=b)   printf("%d\n",(b*min(x,y))+(a*abs(x-y)));
    else    printf("%d\n",b*(min(x,y)+abs(x-y)/2*2)+a*(abs(x-y)%2));
    return 0;
}
