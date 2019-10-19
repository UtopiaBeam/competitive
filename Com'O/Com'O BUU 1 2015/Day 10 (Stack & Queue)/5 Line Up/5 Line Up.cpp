#include<cstdio>
#include<queue>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
queue<P> q1;
queue<int> q2;
char ch;
int x,y;
int main(){
    while(scanf(" %c",&ch) && ch!='E'){
        if(ch=='A'){
            scanf("%d %d",&x,&y);
            q1.push(P(x,y));
            while(!q1.empty() && !q2.empty()){
                if(q1.front().S >= q2.front()){
                    printf("%d %d\n",q1.front().F,q1.front().S-q2.front()),q1.pop(),q2.pop();
                    break;
                }
                q1.pop();
            }
        }
        else{
            scanf("%d",&x);
            q2.push(x);
            while(!q1.empty() && !q2.empty()){
                if(q1.front().S >= q2.front()){
                    printf("%d %d\n",q1.front().F,q1.front().S-q2.front()),q1.pop(),q2.pop();
                    break;
                }
                q1.pop();
            }
        }

    }
    return 0;
}

