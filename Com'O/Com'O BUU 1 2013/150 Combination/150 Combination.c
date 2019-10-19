#include<stdio.h>
#include<stdlib.h>
int n,r,k,a[15],b[15],cnt=0;
void play(int state){
    int i;
    if(state==r){
        cnt++;
        if(cnt==k)
            for(i=0;i<r;i++)
                printf((i!=r-1)? "%d ":"%d\n",b[i]);
            return ;
    }
    else{
        for(i=1;i<=n;i++){
            if(a[i]!=2){
                if(state>0 && i<=b[state-1])    continue;
                a[i]=2;     b[state]=i;
                play(state+1);
                a[i]=0;
            }
        }
    }
}
int main(){
    scanf("%d %d %d",&n,&r,&k);
    cnt=0;
    play(0);
    return 0;
}
