#include<cstdio>
#include<list>
#define itt list<int>::iterator
using namespace std;
list<int> l;
int n,a,b;
int main(){
	scanf("%d %d %d",&n,&a,&b);
	l.push_back(n--),a--,b--;
	if(a+b>n+1){
        printf("IMPOSSIBLE\n");
        return 0;
	}
	while(a || b){
		if(a)   l.push_front(n--),a--;
		if(b)   l.push_back(n--),b--;
		if(n<0){
			printf("IMPOSSIBLE\n");
			return 0;
		}
	}
	itt it=l.begin();
	it++;
	while(n){
		l.insert(it,n--);
		it++,it++;
	}
	for(itt it=l.begin();it!=l.end();it++)
		printf("%d ",*it);
	printf("\n");
	return 0;
}
