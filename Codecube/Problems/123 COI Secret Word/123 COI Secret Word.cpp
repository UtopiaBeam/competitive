#include<cstdio>
#include<cstring>
#include<stack>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int q,c[1000002],t[1000002];
char a[1000002],b[1000002],ans[1000002];
stack<P> st;
int main(){
	scanf("%d",&q);
	while(q--){
		memset(t,0,sizeof(t));
		t[0]=-1;
		scanf(" %s %s",a,b);
		int la=strlen(a),lb=strlen(b);
		int pos=2,cnd=0;
		while(pos<lb){
			if(b[pos-1]==b[cnd])	t[pos++]=++cnd;
			else if(cnd>0)  cnd=t[cnd];
			else	t[pos++]=0;
		}
		int na=0,nb=0;
		while(na+nb<la){
            if(a[na+nb]==b[nb]){
                ;
            }
		}
	}
	return 0;
}
