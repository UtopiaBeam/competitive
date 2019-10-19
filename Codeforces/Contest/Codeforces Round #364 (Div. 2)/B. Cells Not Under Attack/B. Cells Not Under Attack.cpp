#include<cstdio>
long long cr=0,cc=0,n;
int m,x,y,r[100002],c[100002];
int main(){
    scanf("%I64d %d",&n,&m);
    while(m--){
        scanf("%d %d",&x,&y);
        if(!r[x])   cr++,r[x]=1;
        if(!c[y])   cc++,c[y]=1;
        printf("%I64d ",n*n-n*(cr+cc)+cr*cc);
    }
    return 0;
}
