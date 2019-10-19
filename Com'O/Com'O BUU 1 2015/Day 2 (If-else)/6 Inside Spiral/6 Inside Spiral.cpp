/*
TASK: Inside Spiral
AUTHOR: Natchapol Srisang
SCHOOL: Mahidolwittayanusorn School
LANG: C
*/
#include<cstdio>
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    if(n<=m)    printf("%d\n",2*n-2);
    else    printf("%d\n",2*m-1);
    return 0;
}
