#include<cstdio>
#include<vector>
using namespace std;
vector <int> dig;
void base(int num){
    if(num==0)      return ;
    dig.push_back(num%3);
    base(num/3);
}
int main(){
    int n,cnt=0,ans=0;
    scanf("%d",&n);
    base(n);
    for(int i=0;i<dig.size();i++)
        if(dig[i]==1)   cnt++;
        else if(dig[i]==2){
            dig[i]=0,cnt++;
            if(i<dig.size()-1)
                dig[i+1]++;
            else    dig.push_back(1);
        }
        else if(dig[i]>2){
            dig[i]%=3;
            if(i<dig.size()-1)
                dig[i+1]++;
            else    dig.push_back(1);
        }
    printf("%d ",cnt);
    for(int i=dig.size()-1;i>=0;i--)
        ans*=3,ans+=dig[i];
    printf("%d\n",ans);
    return 0;

}
