#include<cstdio>
char a[1000005],b[1000005];
int n,m,t[1000005]={-1},c[1000005],nowa=0,nowb=0,pos=2,cnd=0,cnt=0;
int main(){
    scanf("%d %d %s %s",&n,&m,a,b);
    while(pos<m){
        if(b[pos-1]==b[cnd])
            t[pos++]=++cnd;
        else if(cnd>0)
            cnd=t[cnd];
        else    t[pos++]=0;
    }
    while(nowa+nowb<n){
        if(a[nowa+nowb]==b[nowb]){
            if(nowb==m-1)   cnt++,nowa+=nowb-t[nowb],nowb=t[nowb];
            else    nowb++;
        }
        else{
            if(t[nowb]>-1)  nowa+=nowb-t[nowb],nowb=t[nowb];
            else    nowa++,nowb=0;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
