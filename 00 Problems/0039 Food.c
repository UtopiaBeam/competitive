#include<stdio.h>
int x[15],a[15],b[15],n,m;
void p(int state){
    int i;
    if(state==n){
        for(i=0;i<m;i++)
            if(b[0]==x[i])  return ;
        for(i=0;i<n;i++)
            printf((i!=n-1)? "%d ":"%d\n",b[i]);
        return ;
    }
    else{
        for(i=1;i<=n;i++){
            if(a[i]!=1){
                a[i]=1;     b[state]=i;
                p(state+1);
                a[i]=0;
            }
        }
    }
}
int main(){
    int i;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
        scanf("%d",&x[i]);
    p(0);
    return 0;
}
