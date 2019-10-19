#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
vector<int> g[100002],tp;
stack<int> st;
int n,m,s,e,in[100002];
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&s,&e);
        g[s].push_back(e);
        in[e]++;
    }
    for(int i=1;i<=n;i++)
        if(!in[i])      st.push(i);
    while(!st.empty()){
        s=st.top();
        st.pop();
        tp.push_back(s);
        for(int i=0;i<g[s].size();i++){
            in[g[s][i]]--;
            if(!in[g[s][i]])    st.push(g[s][i]);
        }
    }
    if(tp.size()<n)     printf("no\n");
    else for(int i=0;i<tp.size();i++)
        printf("%d\n",tp[i]);
    return 0;
}
