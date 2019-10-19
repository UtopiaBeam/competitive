#include<cstdio>
int a,cnt=0;
int main(){
    scanf("%d",&a);
    while(a){
        cnt+=a%2;
        a/=2;
    }
    printf("%d\n",cnt);
    return 0;
}
