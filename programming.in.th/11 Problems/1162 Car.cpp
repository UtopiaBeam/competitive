#include<cstdio>
int a[105][45],n,m,t,ans[105];
void play(int now,int len){
    if(now==t){
        for(int i=0;i<t;i++)
            printf("%d\n",ans[i]);
        return ;
    }
    if(len>1 && !a[now+1][len-1]){
        ans[now]=1;     play(now+1,len-1);
    }
    if(!a[now+1][len]){
        ans[now]=3;     play(now+1,len);
    }
    if(len<n && !a[now+1][len+1]){
        ans[now]=2;     play(now+1,len+1);
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&t);
    for(int i=1;i<=t;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    play(0,m);
    return 0;
}
