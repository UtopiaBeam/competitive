#include<cstdio>
#include<cmath>
#define L long long
L a,t=1;
int main(){
    scanf("%I64d",&a);
    if(a%4){
        while(!(a&1)){
            t*=2;
            a/=2;
        }
        if(a==1)    printf("-1\n");
        else{
            L i=a/2;
            printf("%I64d %I64d\n",t*2*(i*(i+1)),t*(2*i*(i+1)+1));
        }
    }
    else    printf("%I64d %I64d\n",3*a/4,5*a/4);
    return 0;
}
