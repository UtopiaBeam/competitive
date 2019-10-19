#include<cstdio>
int n,a,b,c,d,e,s=0;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
        s+=(8*a+6*b+4*c+2*d+e)/8+((8*a+6*b+4*c+2*d+e)%8!=0);
    }
    printf("%d\n",s);
    return 0;
}
