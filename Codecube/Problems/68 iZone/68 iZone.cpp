#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a,s,e,ft[3][1000002],st[1000002];   //0 = R, 1 = G, 2 = B
char ch;
void ud(int c,int x,int v){
    for(;x<=n;x+=-x&x)  ft[c][x]+=v;
}
int get(int c,int s,int e){
    int sum=0;
    for(;s;s-=-s&s)     sum-=ft[c][s];
    for(;e;e-=-e&e)     sum+=ft[c][e];
    return sum;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        ud(i%3,i+1,1),st[i+1]=i%3;
    while(m--){
        scanf("%d %d",&a,&s);
        if(a==1){
            scanf(" %c",&ch);
            ud(st[s],s,-1),ud((ch=='G')+(ch=='B')*2,s,1),st[s]=(ch=='G')+(ch=='B')*2;
        }
        else{
            int mx=0,co=-1,t[3];
            scanf("%d",&e);
            for(int i=0;i<3;i++)
                mx=max(mx,t[i]=get(i,s-1,e));
            for(int i=0;i<3;i++)
                if(mx==t[i]){
                    if(co<0)    co=i;
                    else{
                        co=-1;      break;
                    }
                }
            if(co>=0)   printf("%c\n",(co==0)*'R'+(co==1)*'G'+(co==2)*'B');
            else    printf("None\n");
        }
    }
    return 0;
}
