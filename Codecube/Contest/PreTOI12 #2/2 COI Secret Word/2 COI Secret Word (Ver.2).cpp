#include<cstdio>
#include<cstring>
int q,lps[1000002],m[1000002],f[1000002];
char a[1000002],b[1000002];
int main(){
    scanf("%d",&q);
    while(q--){
        memset(lps,0,sizeof(lps));
        memset(m,0,sizeof(m));
        memset(f,0,sizeof(f));
        scanf(" %s %s",a+1,b+1);
        int la=strlen(a+1),lb=strlen(b+1),nw=2,cnt=0;
        while(nw<lb){
            if(b[nw]==b[cnt+1])     lps[nw]=++cnt;
            else if(cnt>0)  cnt=lps[cnt];
            else    lps[nw++]=0;
        }
        int nb;
        m[1]=1,f[1]=1;
        for(int i=1;i<=la;i++){
            nb=m[i];
            if(b[nb]==a[i+nb]){
                if(nb==lb){
                    ;
                }
            }
        }
    }
    return 0;
}
