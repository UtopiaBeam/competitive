#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int> v;
int mx=0;
char a[1002];
bool f(char a,char b){
    if(a>b) a+=b,b=a-b,a-=b;
    if(a=='A' && b=='T')    return false;
    if(a=='C' && b=='G')    return false;
    return true;
}
int main(){
    scanf(" %s",a);
    int len=strlen(a);
    for(int l=len;l>1;l--){
        for(int i=0;i<=len-l;i++)
            for(int j=0;j<l;j++){
                if(f(a[i+j],a[i+l-1-j]))    break;
                if(j==l-1)  v.push_back(i);
            }
        if(v.size()){
            printf("%d\n%d\n",l,v.size());
            for(int j=0;j<v.size();j++){
                printf("%d\n",v[j]+1);
                for(int k=v[j];k<v[j]+l;k++)    printf("%c",a[k]);
                printf("\n");
                for(int k=v[j]+l-1;k>=v[j];k--)    printf("%c",a[k]);
                printf("\n");
            }
            return 0;
        }
    }
    printf("No palindromic sequence found\n");
    return 0;
}
