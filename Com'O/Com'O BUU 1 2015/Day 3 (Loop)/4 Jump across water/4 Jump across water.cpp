#include<cstdio>
int a,b,c,n,t;
int main(){
    scanf("%d %d %d %d",&a,&b,&c,&n);
    while(n--){
        scanf("%d",&t);
        if(t<=a || (t-a)%(b+c)>b)   printf("no\n");
        else    printf("yes\n");
    }
    return 0;
}
