#include<cstdio>
#include<cstring>
#include<cctype>
#include<vector>
using namespace std;
vector<int> ans[2];
char a[12],b[12],c[1002];
int la,lb,lc,chk=1,s;
int main(){
    gets(a);    gets(b);    gets(c);
    la=strlen(a),lb=strlen(b),lc=strlen(c);
    for(int i=0;i<la;i++)   a[i]=tolower(a[i]);
    for(int i=0;i<lb;i++)   b[i]=tolower(b[i]);
    for(int i=0;i<lc;i++)   c[i]=tolower(c[i]);
    for(int i=0;i<lc;i++){
        if(chk){
            if(!strncmp(c+i,a,la))  s=i+1,chk=0,i+=la-1;
        }
        else if(!strncmp(c+i,b,lb)){
            ans[0].push_back(s),ans[1].push_back(i+lb);
            chk=1,i+=lb-1;
        }
    }
    printf("%d\n",ans[0].size());
    for(int i=0;i<ans[0].size();i++)
        printf("%d %d\n",ans[0][i],ans[1][i]);
    return 0;
}
