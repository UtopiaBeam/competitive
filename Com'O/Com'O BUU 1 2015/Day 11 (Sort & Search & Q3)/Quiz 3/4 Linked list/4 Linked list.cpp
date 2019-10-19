#include<cstdio>
#include<list>
#define IT list<int>::iterator
using namespace std;
list<int> l;
int n,k,c,x,y;
char ch;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)   l.push_back(i);
    while(k--){
        scanf(" %c %d %d",&ch,&x,&y);
        l.remove(x);
        if(ch=='A'){
            for(IT it=l.begin();it!=l.end();it++)
                if(*it==y){
                    l.insert(it,x);     break;
                }
        }
        else{
            for(IT it=l.begin();it!=l.end();it++)
                if(*it==y){
                    l.insert(++it,x);     break;
                }
        }
    }
    for(IT it=l.begin();it!=l.end();it++)
        printf("%d ",*it);
    return 0;
}
