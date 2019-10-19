#include<cstdio>
#include<list>
using namespace std;
class C{
public:
    int c,d;
}t;
int main(){
    int q,tmp;
    scanf("%d",&q);
    while(q--){
        list<C> a,b;
        bool chk=true,f=false;
        for(int i=19;i>=0;i--){
            scanf("%d",&t.c);
            t.d=i;
            a.push_back(t);
        }
        for(int i=19;i>=0;i--){
            scanf("%d",&t.c);
            t.d=i;
            b.push_back(t);
        }
        for(list<C>::iterator A=a.begin(),B=b.begin();A!=a.end() && B!=b.end();A++,B++){
            tmp=A->c+B->c;
            if(tmp){
                chk=false;
                if(f){
                    if(tmp<0)   printf(" - "),tmp=-tmp;
                    else    printf(" + ");
                }
                else{
                    if(tmp==-1)     printf("-"),tmp=-tmp;
                    f=true;
                }
                if(A->d){
                    if(tmp!=1)      printf("%d",tmp);
                    printf("x");
                    if(A->d>1)  printf("^%d",A->d);
                }
                else    printf("%d\n",tmp);
            }
        }
        if(chk)     printf("0");
        printf("\n");
    }
    return 0;
}
