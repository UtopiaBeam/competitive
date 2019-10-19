#include<cstdio>
#include<cstring>
#include<vector>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
char a[2102],b[2102],ra[2102];
int la,lb,s=0;
vector<P> V;
int main(){
    scanf(" %s %s",a,b);
    la=strlen(a),lb=strlen(b);
    for(int i=0;i<la;i++)
        ra[la-1-i]=a[i];
    for(int e=0;e<lb;e++)
        if(!strncmp(a,b+s,e-s+1))
            V.push_back(P(s,e)),s=e+1;
        else if(!strncmp(ra,b+s,e-s+1))
            V.push_back(P(e,s)),s=e+1;
    printf("%d\n",V.size());
    for(int i=0;i<V.size();i++)
        printf("%d %d\n",V[i].F,V[i].S);
    return 0;
}
