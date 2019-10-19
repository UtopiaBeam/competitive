#include<cstdio>
#include<set>
using namespace std;
int n,t;
set<int> s;
set<int>::iterator it,itt;
set<int>::reverse_iterator rit;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&t);
        if(s.empty()){
            s.insert(t);    continue;
        }
        it=s.begin();
        if(*it==0){
            int cnt=1;
            for(it++;it!=s.end();it++)
                if(t+cnt>=*it){
                    itt=it--;   cnt++;
                    s.erase(itt);
                }
            for(int i=0;i<=cnt;i++)  s.insert(t+i);
            s.erase(0);
        }
        for(;it!=s.end();it++){
            if(*it>t)   break;
            if(*it==t){
                t--;    break;
            }
            s.insert((*it)-1);
            itt=it--;
            s.erase(itt);
            t--;
        }
        s.insert(t);
    }
    for(rit=s.rbegin();rit!=s.rend();rit++)  printf("%d\n",*rit);
    return 0;
}
