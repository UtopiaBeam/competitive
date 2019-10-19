/*
TASK: Intro014
AUTHOR: Natchapol Srisang
SCHOOL: Mahidolwittayanusorn School
LANG: C
*/
#include<cstdio>
int main(){
    char a[5],b[5];
    int x;
    scanf(" %s %s",a,b);
    x=(a[0]-'0')*8+(a[1]-'0')*4+(a[2]-'0')*2+(a[3]-'0')+(b[0]-'0')*8+(b[1]-'0')*4+(b[2]-'0')*2+(b[3]-'0');
    printf("%d%d%d%d%d\n",(x/16)%2,(x/8)%2,(x/4)%2,(x/2)%2,x%2);
    return 0;
}

