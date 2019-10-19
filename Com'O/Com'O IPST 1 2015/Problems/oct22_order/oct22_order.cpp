#include<cstdio>
int pre[1002],post[1002],n;
void in(int ps,int pe,int Ps,int Pe){
    if(ps>pe)       return ;
    if(Ps>Pe)       return ;
    int root=post[Pe],cnt=0;
    for(int i=pe;i>ps;i--){
        cnt++;
        if(pre[i]==post[Pe-1])
            break;
    }
    in(ps+1,pe-cnt,Ps,Pe-cnt-1);
    printf("%d ",root);
    in(pe-cnt+1,pe,Pe-cnt,Pe-1);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)    scanf("%d",&pre[i]);
    for(int i=0;i<n;i++)    scanf("%d",&post[i]);
    in(0,n-1,0,n-1);
    return 0;
}
