#include<stdio.h>
struct player{
    char name[30];
    int x,y,job,hp;
};
player p;
int main(){
    scanf(" %s %d %d %d %d",p.name,&p.x,&p.y,&p.job,&p.hp);
    printf("%s %d %d %05d %d\n",p.name,p.x,p.y,p.job,p.hp);
    return 0;
}
