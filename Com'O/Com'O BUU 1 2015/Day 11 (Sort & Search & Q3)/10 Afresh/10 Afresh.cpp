#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
map<int,int> m_f,m_in;
int n,c,a[1002];
bool cmp(int x,int y){
    if(m_f[x]!=m_f[y])  return m_f[x]>m_f[y];
    return m_in[x]<m_in[y];
}
int main(){
    scanf("%d %d",&n,&c);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        m_f[a[i]]++;
        if(!m_in[a[i]]) m_in[a[i]]=i+1;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
