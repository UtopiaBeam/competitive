#include<cstdio>
#include<vector>
using namespace std;
int n,a[102],ans=0;
vector<int> v;
int abs(int x){
    if(x<0)     return -x;
    return x;
}
int gcd(int x,int y){
    if(x%y)     return gcd(y,x%y);
    return y;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            v.push_back(abs(a[i]-a[j]));
    for(int i=0;i<v.size();i++)
        ans=gcd(ans,v[i]);
    int cnt=1;
    for(int i=2;i*i<=ans;i++){
        if(ans%i==0){
            if(i*i==ans)    cnt++;
            else    cnt+=2;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
