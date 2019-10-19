#include<stdio.h>
int main(){
    int a=1,b=2,c=3,*p,*q;
    p=&a;
    printf("p = %p\n",p);
    printf("*p = %d\n",*p);
    q=&b;
    printf("q = %p\n",q);
    printf("*q = %d\n",*q);
    c=*p;
    printf("c = %d\n",c);
    p=q;
    printf("*p = %d\n",*p);
    printf("*q = %d\n",*q);
    printf("p = %p\n",p);
    printf("q = %p\n",q);
    *p=13;
    printf("*p = %d\n",*p);
    printf("*q = %d\n",*q);
    return 0;
}
