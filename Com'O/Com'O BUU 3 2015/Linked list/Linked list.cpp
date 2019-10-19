#include<cstdio>
int n,k,x,y,f[500002],b[500002];
char ch;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        f[i]=i-1,b[i]=(i+1)%(n+1);
    while(k--){
        scanf(" %c %d %d",&ch,&x,&y);
        if(ch=='A'){
            f[b[x]]=f[x];
            b[f[x]]=b[x];
            f[x]=f[y];
            f[y]=x;
            b[x]=y;
            b[f[x]]=x;
        }
        else{
            f[b[x]]=f[x];
            b[f[x]]=b[x];
            f[x]=y;
            f[b[y]]=x;
            b[x]=b[y];
            b[y]=x;
        }
    }
    for(int i=1;i<=n;i++)
        if(!f[i]){
            x=i;    break;
        }
    while(x){
        printf("%d ",x);
        x=b[x];
    }
    return 0;
}
