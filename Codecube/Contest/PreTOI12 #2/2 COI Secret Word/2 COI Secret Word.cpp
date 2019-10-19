#include<cstdio>
#include<cstring>
int q,c[1000002],t[1000002];
char a[1000002],b[1000002],ans[1000002];
int main(){
    scanf("%d",&q);
    while(q--){
        memset(t,0,sizeof(t));
        t[0]=-1;
        scanf(" %s %s",a,b);
        int lb=strlen(b);
        int pos=2,cnd=0;
        while(pos<lb){
            if(b[pos-1]==b[cnd])    t[pos++]=++cnd;
            else if(cnd>0)  cnd=t[cnd];
            else    t[pos++]=0;
        }
        int chk;
        do{
            memset(ans,'\0',sizeof(ans));
            memset(c,0,sizeof(c));
            chk=0;
            int la=strlen(a),lans=0;
            int nowa=0,nowb=0;
            while(nowa+nowb<la){
                if(b[nowb]==a[nowa+nowb]){
                    if(nowb==lb-1)   c[nowa]=1,nowa+=nowb-t[nowb],nowb=t[nowb];
                    else    nowb++;
                }
                else{
                    if(t[nowb]>-1)     nowa+=nowb-t[nowb],nowb=t[nowb];
                    else    nowa++,nowb=0;
                }
            }
            for(int i=0;i<la;i++)
                if(c[i])    i+=lb-1,chk=1;
                else    ans[lans++]=a[i];
            strcpy(a,ans);
        }while(chk);
        if(strlen(ans)>0)     printf("%s\n",ans);
        else    printf("No COI Secret Code\n");
    }
    return 0;
}
