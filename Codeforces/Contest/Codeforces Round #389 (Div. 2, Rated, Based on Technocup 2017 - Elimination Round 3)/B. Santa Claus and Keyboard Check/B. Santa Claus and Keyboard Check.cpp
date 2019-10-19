#include<cstdio>
#include<vector>
#define P pair<char,char>
#define F first
#define S second
using namespace std;
int g[30][30],cnt[30];
char a[1002],b[1002];
vector<P> v;
int main(){
    scanf(" %s %s",a,b);
    for(int i=0;a[i];i++)
        if(!g[a[i]-'a'][b[i]-'a']){
            g[a[i]-'a'][b[i]-'a']=1;
            g[b[i]-'a'][a[i]-'a']=1;
            cnt[a[i]-'a']++;
            if(a[i]!=b[i])  cnt[b[i]-'a']++;
        }
    for(int i=0;i<26;i++){
        if(cnt[i]>1){
            printf("-1\n");
            return 0;
        }
        for(int j=i+1;j<26;j++){
            if(cnt[j]>1){
                printf("-1\n");
                return 0;
            }
            if(g[i][j])
                v.push_back(P(i+'a',j+'a'));
        }
    }
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++)
        printf("%c %c\n",v[i].F,v[i].S);
    return 0;
}
