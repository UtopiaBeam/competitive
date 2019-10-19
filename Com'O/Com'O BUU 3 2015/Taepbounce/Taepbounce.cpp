#include <cstdio>
#include <vector>
#include <algorithm>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
vector<P> b;
vector<int> a;
long long sum=0;
int t;
int main(){
	scanf("%d",&t);
	a.push_back(0);
	for(int i=1;;i++){
		scanf("%d",&t);
		if(!t)		break;
		a.push_back(t);
		b.push_back(P(-t,i));
	}
	a.push_back(0);
	if(b.empty()){
		printf("0\n");
		return 0;
	}
	sort(b.begin(),b.end());
	int s=b[0].S;
	for(int i=1;i<b.size();i++){
		if(!a[b[i].S])
			continue;
		if(s>b[i].S){
			sum+=a[b[i].S-1];
			a[b[i].S-1]=0;
		}
		else{
			sum+=a[b[i].S+1];
			a[b[i].S+1]=0;
		}
		s=b[i].S;
	}
	printf("%lld\n",sum);
	return 0;
}
