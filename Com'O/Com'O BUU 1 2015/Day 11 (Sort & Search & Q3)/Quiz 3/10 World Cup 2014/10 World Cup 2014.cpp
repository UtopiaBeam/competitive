#include<cstdio>
#include<algorithm>
using namespace std;
class C{
public:
    int w,l,tie,s,name,win,lose;
    C(){
        w=0,l=0,tie=0,s=0,name=0,win=0,lose=0;
    }
};
int n;
char a,b,c,d;
bool cmp(C a,C b){
    if(a.s!=b.s)    return a.s > b.s;
    if(a.w-a.l!=b.w-b.l) return a.w-a.l > b.w-b.l;
    if(a.w!=b.w)    return a.w > b.w;
    return a.name < b.name;
}
int main(){
    scanf("%d",&n);
    for(int t=1;t<=n;t++){
        C z[5];
        for(int i=0;i<4;i++)    z[i].name=i;
        for(int i=0;i<6;i++){
            scanf(" %c %c %d %d",&a,&b,&c,&d);
            z[a-'A'].w+=c,z[a-'A'].l+=d,z[b-'A'].w+=d,z[b-'A'].l+=c;
            if(c>d)     z[a-'A'].s+=3,z[a-'A'].win++,z[b-'A'].lose++;
            else if(d>c)    z[b-'A'].s+=3,z[a-'A'].lose++,z[b-'A'].win++;
            else    z[a-'A'].s++,z[b-'A'].s++,z[a-'A'].tie++,z[b-'A'].tie++;
        }
        sort(z,z+n,cmp);
        printf("Case #%d:\n",t);
        for(int i=0;i<4;i++)
            printf("%c %d %d %d %d %d %d\n",z[i].name+'A',z[i].win,z[i].tie,z[i].lose,z[i].w,z[i].l,z[i].s);
    }
    return 0;
}
