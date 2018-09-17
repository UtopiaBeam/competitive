#include<stdio.h>
int k,w,l;
char a[50010];
void play(int state,int w,int l){
    if(w>=k||l>=k){
        for(int i=1;i<state;i++)
            printf("%c ",a[i]);
        printf("\n");
        return ;
    }
    a[state]='W';
    play(state+1,w+1,l);
    a[state]='L';
    play(state+1,w,l+1);
}
int main(){
    scanf("%d %d %d",&k,&w,&l);
    play(1,w,l);
    return 0;
}
