#include<cstdio>
#include<vector>
using namespace std;
vector<int> r[25];
int k,now=0;
char s[1005],ans[1005];
int main(){
    scanf("%d %s",&k,s);
    if(k==1){
        printf("%s\n",s);   return 0;
    }
    for(int i=0;s[i];i++){
        if((i/(k-1))%4==0)
            r[k-1-(i%(k-1))].push_back(i);
        else if((i/(k-1))%4==1)
            r[0].push_back(i);
        else if((i/(k-1))%4==2)
            r[i%(k-1)].push_back(i);
        else    r[k-1].push_back(i);
    }
    for(int i=0;i<k;i++)
        for(int j=0;j<r[i].size();j++)
            ans[r[i][j]]=s[now++];
    printf("%s\n",ans);
    return 0;
}
