/*
TASK: Intro011
AUTHOR: Natchapol Srisang
SCHOOL: Mahidolwittayanusorn School
LANG: C
*/
#include<cstdio>
int main(){
    int a;
    scanf("%d",&a);
    a%=64;
    printf("%d %d\n",7*((a/8)%2)+(1-2*((a/8)%2))*a%8,a/8);
    return 0;
}
