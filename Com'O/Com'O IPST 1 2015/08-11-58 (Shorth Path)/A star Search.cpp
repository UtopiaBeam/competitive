#include<cstdio>
#include<queue>
using namespace std;
int r,c,b[102][102];
char a[102][102];
struct S{
    int x,y;
    double g,h;
    double f(){
        return g+h;
    }
    S(double g=0,double h=0):
        g(g), h(h){}
}t;
struct cmp{
    bool operator()(S a,S b){
        return a.f() < b.f();
    }
};
priority_queue<S,vector<S>,cmp> q;
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)
        scanf(" %s",a[i]);
    scanf("%d %d",&t.x,&t.y);
    q.push(t);
    while(!q.empty()){
        t=q.top();
        q.pop();
    }
    return 0;
}
