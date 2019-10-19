#include<cstdio>
int a[200005],b[200005],t[200005]={-1},n,m,cnt=0;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
        scanf("%d",&b[i]);
    if(m==1){
        printf("%d\n",n);   return 0;
    }
    n--,m--;
    for(int i=0;i<n;i++)
        a[i]-=a[i+1];
    for(int i=0;i<m;i++)
        b[i]-=b[i+1];
    int nowa=0,nowb=0,pos=2,cnd=0;
    while(pos<m){
        if(b[pos-1]==b[cnd])    t[pos++]=++cnd;
        else if(cnd>0)  cnd=t[cnd];
        else    t[pos++]=0;
    }
    while(nowa+nowb<n){
        if(b[nowb]==a[nowa+nowb]){
            if(nowb==m-1)   cnt++,nowa+=nowb-t[nowb],nowb=t[nowb];
            else    nowb++;
        }
        else{
            if(t[nowb]>-1)     nowa+=nowb-t[nowb],nowb=t[nowb];
            else    nowa++,nowb=0;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
