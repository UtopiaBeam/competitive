/*
TASK: Intro006
AUTHOR: Natchapol Srisang
SCHOOL: Mahidolwittayanusorn School
LANG: C
*/
#include<cstdio>
int main(){
    char a;
    scanf("%c",&a);
    printf("%c\n",(a-'a'+27)%26+'a');
    return 0;
}


