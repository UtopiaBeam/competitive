#include<stdio.h>
void solve(int n,int str,int pig,int tar){
    if(n==1)    printf("Move the disk from pole %d to pole %d\n",str,tar);
    else{
        solve(n-1,str,tar,pig);
        printf("Move the disk from pole %d to pole %d\n",str,tar);
        solve(n-1,pig,str,tar);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    solve(n,1,2,3);
    return 0;
}
