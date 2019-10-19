#include<cstdio>
int N,M,P;
bool chk(int n,int m,int p){
    if(m==0)    return (n>0) || (p==P);
    bool t=true;
    for(int i=1;i<=n-m+1;i++){
        if(p+i==P || i==P)  continue;
        if(p+i<P)           t=t && chk(n-i,m-1,p+i);
        else if(i>P)        t=t && chk(n-i,m-1,0);
        else    t=t && chk(n-i,m-1,p);
    }
    return t;
}
int main(){
    while(1){
        scanf("%d",&N);
        if(!N)      return 0;
        scanf("%d %d",&M,&P);
        if(chk(N,M,0))  printf("yes\n");
        else        printf("no\n");
    }
}
