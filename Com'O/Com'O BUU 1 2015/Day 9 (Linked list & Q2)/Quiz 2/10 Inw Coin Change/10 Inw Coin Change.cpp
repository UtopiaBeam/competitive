#include<cstdio>
int n,k,a[22];
void f(int x,int s){
    if(x==0){
        if(--k==0){
            for(int i=0;i<s;i++)
                printf("%d",a[i]);
            return ;
        }
    }
    for(int i=1;i<=x;i++){
        a[s]=i;
        f(x-i,s+1);
    }
}
int main(){
    scanf("%d %d",&n,&k);
    f(n,0);
    return 0;
}
