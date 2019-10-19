#include<cstdio>
#include<cstdlib>
int a,b,c,d,t,cnt=0;
int main(){
    scanf("%d %d %d %d",&a,&b,&c,&d);
    while(a || b || c || d){
        printf("%d\t%d\t%d\t%d\n",a,b,c,d);
        t=a,a=abs(a-b),b=abs(b-c),c=abs(c-d),d=abs(d-t),cnt++;
    }
    printf("0\t0\t0\t0\n%d\n",cnt);
    return 0;
}
