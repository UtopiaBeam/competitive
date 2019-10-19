#include<cstdio>
#include<queue>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
priority_queue<P> q;
int n,m,w,v;
char ch;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n+m;i++){
        scanf(" %c",&ch);
        if(ch=='T'){
            scanf("%d %d",&w,&v);
            q.push(P(-w,v));
        }
        else if(q.empty())  printf("0\n");
        else{
            printf("%d\n",q.top().S);
            q.pop();
        }
    }
    return 0;
}
