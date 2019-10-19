#include<cstdio>
#include<queue>
using namespace std;
#define P pair<int,int>
#define F first
#define S second
int n,m1,m2,x,y,a[1000002];
char ch;
priority_queue<P> H;
int main(){
    scanf("%d %d %d",&n,&m1,&m2);
    for(int i=1;i<=n;i++)   H.push(P(0,i));
    for(int i=0;i<m1+m2;i++){
        scanf(" %c",&ch);
        if(ch=='L'){
            scanf(" %d %d",&y,&x);
            a[x]++;
            H.push(P(a[x],x));
        }
        else if(ch=='C'){
            scanf(" %d %d",&y,&x);
            a[x]+=3;
            H.push(P(a[x],x));
        }
        else if(ch=='D'){
            while(a[H.top().S]<0)   H.pop();
            a[H.top().S]=-1;
        }
        else{
            while(!H.empty() && a[H.top().S]<0)   H.pop();
            printf("%d\n",H.top().S);
        }
//        for(int j=1;j<=n;j++)
//            printf("%d ",a[j]);
//        printf("\n");
    }
    return 0;
}
