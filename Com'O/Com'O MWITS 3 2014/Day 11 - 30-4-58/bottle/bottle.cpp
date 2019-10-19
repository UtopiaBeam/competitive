#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
priority_queue <pair<int,int> > heap;
vector<int> b;
int n,m,h,mark[100005];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&h);
        heap.push(make_pair(h,i));
    }
    while(m--){
        b.clear();
        int cnt=0,now;
        scanf("%d",&h);
        while(!heap.empty() && heap.top().first>h){
            now=heap.top().second;
            if(!mark[now]){
                b.push_back(now);
                if(now>0 && !mark[now-1])   b.push_back(now-1);
                if(now<n-1 && !mark[now+1]) b.push_back(now+1);
            }
            heap.pop();
        }
        for(int i=0;i<b.size();i++)
            if(!mark[b[i]])  mark[b[i]]=1,cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
