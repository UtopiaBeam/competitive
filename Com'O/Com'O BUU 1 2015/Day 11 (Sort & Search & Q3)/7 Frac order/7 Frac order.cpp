#include<cstdio>
#include<map>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
map<double,P> m;
map<double,int> t;
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<=n;j++){
            double p=(double)i/j;
            if(!t[p])   t[p]=1,m[p]=P(i,j);
        }
    for(map<double,P>::iterator it=m.begin();it!=m.end();it++)
        printf("%d/%d\n",it->S.F,it->S.S);
    printf("1/1\n");
    return 0;
}
