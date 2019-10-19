#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#define F first
#define S second
#define B begin()
#define E end()
#define Si size()
#define rit map<int,int>::reverse_iterator
#define itt map<int,int>::iterator
using namespace std;
int n,m,p,q;
char c;
map<int,int> b,s;
vector<int> sp;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf(" %c %d %d",&c,&p,&q);
        if(c=='B')  b[p]+=q;
        else    s[p]+=q;
    }
    p=0;
    for(itt it=s.begin();it!=s.end() && p<m;p++,it++)
        sp.push_back((*it).F);
    for(int i=sp.size()-1;i>=0;i--)
        printf("S %d %d\n",sp[i],s[sp[i]]);
    p=0;
    for(rit it=b.rbegin();it!=b.rend() && p<m;p++,it++)
        printf("B %d %d\n",(*it).F,(*it).S);
    return 0;
}
