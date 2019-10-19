#include<string>
#include<cctype>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
map <string,vector <string> > adj;
int n,Max=0;
void dfs(int h,string now){
    if(adj[now].size()==0){
        Max=max(Max,h);   return ;
    }
    for(int i=0;i<adj[now].size();i++)
        dfs(h+1,adj[now][i]);
}
int main(){
    cin >> n;
    while(n--){
        string from,to,b;
        cin >> to >> b >> from;
        for(int i=0;i<from.length();i++)
            if(isupper(from.at(i))) from.at(i)=tolower(from.at(i));
        for(int i=0;i<to.length();i++)
            if(isupper(to.at(i))) to.at(i)=tolower(to.at(i));
        adj[from].push_back(to);
    }
    dfs(1,"polycarp");
    cout << Max << endl;
    return 0;
}
