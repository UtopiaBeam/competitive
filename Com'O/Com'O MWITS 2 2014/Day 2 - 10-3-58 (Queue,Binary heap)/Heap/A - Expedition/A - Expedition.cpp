#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
PII a[10010];
int main(){
    int t,n,l,p;
    scanf("%d",&t);
    while(t--){
        priority_queue <int> q;
        int cnt=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d %d",&l,&p);
            a[i]=PII(-l,p);
        }
        scanf("%d %d",&l,&p);
        for(int i=0;i<=n;i++)
            a[i].first+=l;
        sort(a,a+n);
        a[n]=PII(l,0);
        for(int i=0;i<=n;i++){
            while(p<a[i].first && !q.empty()){
                p+=q.top();
                q.pop();
                cnt++;
            }
            if(p<a[i].first){
                cnt=-1;     break;
            }
            q.push(a[i].second);
        }
        printf("%d\n",cnt);
    }
    return 0;
}
