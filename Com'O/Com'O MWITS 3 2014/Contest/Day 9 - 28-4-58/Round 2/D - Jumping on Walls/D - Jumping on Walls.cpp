#include<cstdio>
#include<queue>
using namespace std;
class move{
public:
    int wall,h,d;
}tmp,now;
queue <move> q;
int n,k;
char a[2][100005];
int main(){
    scanf("%d %d %s %s",&n,&k,a[0],a[1]);
    tmp.wall=0,tmp.h=0,tmp.d=0;
    q.push(tmp);
    while(!q.empty()){
        now=q.front();   q.pop();
        if(now.h>n){
            printf("YES\n");    return 0;
        }
        tmp.wall=now.wall;
        tmp.d=now.d+1;
        tmp.h=now.h+1;
        if(tmp.h>=tmp.d && a[tmp.wall][tmp.h]!='X')     q.push(tmp);
        tmp.h=now.h-1;
        if(tmp.h>=tmp.d && a[tmp.wall][tmp.h]!='X')     q.push(tmp);
        tmp.h=now.h+k,tmp.wall=1-now.wall;
        if(tmp.h>=tmp.d && a[tmp.wall][tmp.h]!='X')     q.push(tmp);
    }
    printf("NO\n");
    return 0;
}
