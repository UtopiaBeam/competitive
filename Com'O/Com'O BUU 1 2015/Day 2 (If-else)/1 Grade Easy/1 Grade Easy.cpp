/*
TASK: Grade Easy
AUTHOR: Natchapol Srisang
SCHOOL: Mahidolwittayanusorn School
LANG: C
*/
#include<cstdio>
int main(){
    int x;
    scanf("%d",&x);
    if(x>=80)   printf("A\n");
    else if(x>=75)  printf("B+\n");
    else if(x>=70)  printf("B\n");
    else if(x>=65)  printf("C+\n");
    else if(x>=60)  printf("C\n");
    else if(x>=55)  printf("D+\n");
    else if(x>=50)  printf("D\n");
    else    printf("F\n");
    return 0;
}
