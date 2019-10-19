#include<cstdio>
#include<vector>
#define f (1-2*(k%2))
using namespace std;
vector<int> path;
char a[15];
int m,chk=1;
int abs(int n){
    return (n>=0)?   n:-n;
}
void dfs(int i,int j,int k){
    if(i>10 || i<-10 || !chk)   return ;
    if(k==m+1){
        printf("YES\n");
        for(int l=0;l<path.size();l++)
            printf("%d ",path[l]);
        chk=0;  return ;
    }
    for(int l=0;a[l];l++){
        if(chk && a[l]=='1' && l+1!=j && f*(i+f*(l+1))>0){
            path.push_back(l+1);
            dfs(i+f*(l+1),l+1,k+1);
            path.pop_back();
        }
    }
}
int main(){
    scanf(" %s %d",a,&m);
    dfs(0,0,1);
    if(chk)     printf("NO\n");
    return 0;
}
