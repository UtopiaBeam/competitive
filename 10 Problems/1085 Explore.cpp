#include<cstdio>
#include<vector>
using namespace std;
int room[500005],Max=0,n,m,k,chk=0;
vector <int> warp[500005];
void play(int now){
    if(now==n){
        chk=1;      return ;
    }
    if(!chk){
        if(Max<now)     Max=now;
        if(!room[now])  play(now+1);
        for(int i=0;i<warp[now].size();i++)
            play(warp[now][i]);
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&k);
    while(m--){
        int str,end;
        scanf("%d %d",&str,&end);
        warp[str].push_back(end);
    }
    while(k--){
        scanf("%d",&m);
        room[m]=1;
    }
    play(1);
    if(chk)     printf("1\n");
    else    printf("0 %d\n",Max);
    return 0;
}
