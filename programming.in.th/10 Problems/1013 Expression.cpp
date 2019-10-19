#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector <int> prio;
char a[70],opr[]="+*^";
void play(int str,int end,int now){
    if(now==prio.size()){
        for(int i=str;i<=end;i++)
            printf("%c",a[i]);
        printf("\n");
        return ;
    }
    int in,chkplus=0,chkmul=0,chkpow=0,par=0,chk=1,from,to;
    for(int i=str;i<=end;i++){
        if(a[i]=='(')   par++;
        if(a[i]==')')   par--;
        if(par)     continue;
        if(a[i]=='+')       chkplus=1;
        else if(a[i]=='*')  chkmul=1;
        else if(a[i]=='^')  chkpow=1;
    }
    if(chkplus)     in=0;
    else if(chkmul) in=1;
    else if(chkpow) in=2;
    else in=3;
    if(a[str]=='(' && a[end]==')'){
        int chkp=1;
        for(int i=str+1;i<end && chkp;i++)
            if(a[i]=='(' || a[i]==')')  chkp=0;
        if(chkp || in==3){
            if(--prio[now]==0)  play(str+1,end-1,now+1);
            else    printf("null\n");
            return ;
        }
    }
    for(int i=str;i<=end;i++){
        if(a[i]=='(')   par++;
        if(a[i]==')')   par--;
        if(chk)     from=i,chk=0;
        if(!par){
            if(a[i]==opr[in]){
                if(--prio[now]==0){
                    play(from,to,now+1);
                    return ;
                }
                chk=1;
            }
        }
        to=i;
        if(i==end){
            if(--prio[now]==0)  play(from,to,now+1);
            else    printf("null\n");
        }
    }
}
int main(){
    int q,n;
    scanf(" %s %d",a,&q);
    int len=strlen(a);
    while(q--){
        prio.clear();
        while(scanf("%d",&n) && n)
            prio.push_back(n);
        for(int i=prio.size()-1;i>=0;i--)
            printf("op(%d,",prio[i]);
        printf("p");
        for(int i=0;i<prio.size();i++)
            printf(")");
        printf("=");
        play(0,len-1,0);
    }
    return 0;
}
