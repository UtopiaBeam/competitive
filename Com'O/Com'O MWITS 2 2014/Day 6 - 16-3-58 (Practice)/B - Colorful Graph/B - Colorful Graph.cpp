#include<bits/stdc++.h>
using namespace std;
bool visited[100005];
vector <int> neighbor[100005];
int n,m,color[100005],cnt[100005];
bool find(int str,int end){

}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&color[i]);
    while(m--){
        int str,end;
        scanf("%d %d",&str,&end);
        if(color[str]!=color[end] && !find(str,end))
    }
}
