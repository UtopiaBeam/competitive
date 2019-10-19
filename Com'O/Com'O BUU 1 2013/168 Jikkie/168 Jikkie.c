#include<stdio.h>
int A,B,C,d[25];
int mark[25][25][25];
void play(int a,int b,int c){
    if(a<0||a>A||b<0||b>B||c<0||c>C)    return ;
    if(a==0)    d[c]=1;
    if(mark[a][b][c])   return ;
    mark[a][b][c]=1;
    play(0,a+b,c);      play(a+b-B,B,c);    //a->b
    play(0,b,a+c);      play(a+c-C,b,C);    //a->c
    play(a+b,0,c);      play(A,b+a-A,c);    //b->a
    play(a,0,b+c);      play(a,b+c-C,C);    //b->c
    play(a+c,b,0);      play(A,b,c+a-A);    //c->a
    play(a,b+c,0);      play(a,B,c+b-B);    //c->b
}
int main(){
    int i;
    scanf("%d %d %d",&A,&B,&C);
    play(0,0,C);
    for(i=0;i<=20;i++)
        if(d[i])    printf("%d ",i);
    printf("\n");
    return 0;
}
