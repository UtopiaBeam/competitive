#include<cstdio>
#define min(x,y) x<y? x:y
#define abs(x) x>0? x:-x
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d %d\n",min(a,b),abs((a-b)/2));
    return 0;
}
