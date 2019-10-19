#include<cstdio>
int a,b;
int main(){
    scanf("%d %d",&a,&b);
    for(int i=b;i>=a;i--)
        if(i%400==0 || (i%4==0 && i%100!=0))
            printf("%d\n",i);
    return 0;
}
