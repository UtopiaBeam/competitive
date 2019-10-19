#include<stdio.h>
int main(){
    int a[5],cnt=0,in;
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    while(a[0]!=1||a[1]!=1||a[2]!=1){
        in=(a[0]>a[1])?     0:1;
        in=(a[in]>a[2])?    in:2;
        a[in]/=2;   cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
