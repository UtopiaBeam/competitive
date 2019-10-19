#include<stdio.h>
int a[1010],n;
void play(int state,int num){
    if(state==n){
        for(int i=0;i<n;i++)
            printf("%d",a[i]);
        printf("\n");
        return ;
    }
    a[state]=0;
    play(state+1,0);
    a[state]=1;
    play(state+1,0);
}
int main(){
    scanf("%d",&n);
    play(0,0);
    return 0;
}
