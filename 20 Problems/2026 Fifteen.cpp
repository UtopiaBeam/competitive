#include<cstdio>
#include<queue>
using namespace std;
int x,y;
struct S{
    int x,y;
    int g,h;
    int a[5][5];
    int f(){
        return g+h;
    }
    S(int g,int h):
        g(g),h(h){};
}t;
int main(){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            scanf("%d",&a[i][j]);
            if(!a[i][j])    x=i,y=j;
        }
}
