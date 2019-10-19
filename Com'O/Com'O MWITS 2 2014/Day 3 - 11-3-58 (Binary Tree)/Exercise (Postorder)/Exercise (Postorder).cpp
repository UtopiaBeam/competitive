#include<cstdio>
int pre[1010],in[1010],post[1010],n,now=0;
void f(int str,int end){
    if(str>end)     return ;
    int mark,root;
    for(int i=str;i<=end;i++)
        if(in[i]==pre[now]){
            root=pre[now++],mark=i;
            break;
        }
    f(str,mark-1);
    f(mark+1,end);
    printf("%d ",root);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&pre[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&in[i]);
    f(0,n-1);
    printf("\n");
    return 0;
}
