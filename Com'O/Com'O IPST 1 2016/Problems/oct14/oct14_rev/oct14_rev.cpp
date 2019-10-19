#include<cstdio>
char a[1002];
void rev(int x){
    if(!a[x])   return ;
    rev(x+1);
    printf("%c",a[x]);
}
int main(){
    gets(a);
    rev(0);
    return 0;
}
