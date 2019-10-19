#include<stdio.h>
int n,a[1010];
void play(int state,int num){
    if(state==n){
        for(int i=0;i<n;i++)
            printf("%d",a[i]);
        printf("\n");
        return ;
    }
    a[state]=num;
    play(state+1,0);
    a[state]=1-num;
    play(state+1,1);
}
int main(){
    scanf("%d",&n);
    play(0,0);
    return 0;
}
