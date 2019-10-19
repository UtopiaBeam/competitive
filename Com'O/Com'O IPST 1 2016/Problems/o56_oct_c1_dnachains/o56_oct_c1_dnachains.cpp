#include<cstdio>
#include<utility>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int l,n,m,b[100002],nw=1,lim=1;
char ch;
P a[100002];
int main(){
    scanf("%d %d",&l,&n);
    while(l--){
        scanf("%d",&m);
        for(int i=lim;i<m+lim-1;i++)
            a[i].S=i+1,a[i+1].F=i;
        lim+=m;
    }
    while(n--){
        scanf(" %c",&ch);
        if(ch=='F'){
            if((!a[nw].F && b[a[nw].S]) || (!a[nw].S && b[a[nw].F]) || (!a[nw].F && !a[nw].S));
            else{
                b[nw]=1;
                if(!b[a[nw].F] && a[nw].F)     nw=a[nw].F;
                else        nw=a[nw].S;
            }
        }
        else if(ch=='B'){
            if((!a[nw].F && !b[a[nw].S]) || (!a[nw].S && !b[a[nw].F]));
            else{
                if(b[a[nw].F])  nw=a[nw].F;
                else    nw=a[nw].S;
                b[nw]=0;
            }
        }
        else{
            scanf("%d",&l);
            if(b[a[nw].F] || a[nw].F==0 && !b[a[nw].S]){
                m=a[nw].S;
                a[nw].S=l;
            }
            else if(b[a[nw].S] || a[nw].S==0 && !b[a[nw].F]){
                m=a[nw].F;
                a[nw].F=l;
            }
            if(a[l].F==0)   a[l].F=nw;
            else    a[l].S=nw;
            if(a[m].F==nw)  a[m].F=0;
            else    a[m].S=0;
            b[nw]=1; nw=l;
        }
        printf("%d\n",nw);
    }
    return 0;
}
