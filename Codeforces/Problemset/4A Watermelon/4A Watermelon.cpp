#include<cstdio>
int w;
int main(){
    scanf("%d",&w);
    printf("%s\n",(w<=2 || (w-2)%2)? "NO":"YES");
    return 0;
}
