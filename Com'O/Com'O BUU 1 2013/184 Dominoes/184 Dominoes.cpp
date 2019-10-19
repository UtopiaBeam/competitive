#include<stdio.h>
int a[20],n;
void play(int state){
    if(state>n)     return ;
    if(state==n){
        for(int i=0;i<n;i++)
            if(a[i]==-1) printf("--\n");
            else if(a[i]==1){
                printf("||\n");
                i++;
            }
        printf("E\n");
        return ;
    }
    a[state]=-1;
    play(state+1);
    a[state]=1;
    play(state+2);
}
int main(){
    scanf("%d",&n);
    play(0);
    return 0;
}
