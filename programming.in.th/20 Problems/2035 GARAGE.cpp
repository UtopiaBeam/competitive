#include<cstdio>
#include<queue>
using namespace std;
queue<int> q;
int n,m,w[2002],x,cnt=0,r[102],a[102],b[2002],sum=0;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&r[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&w[i]);
    for(int i=0;i<2*m;i++){
        scanf("%d",&x);
        if(x>0){
            if(cnt<n)
                for(int j=0;j<n;j++)
                    if(!a[j]){
                        sum+=w[x]*r[j];
                        cnt++;      a[j]=1;
                        b[x]=j;
                        break;
                    }
            else        q.push(x);
        }
        else{
            x=-x;
            a[b[x]]=0;      cnt--;
            while(!q.empty() && cnt<n)
                for(int j=0;j<n;j++)
                    if(!a[j]){
                        sum+=w[q.front()]*r[j];
                        a[j]=1;     cnt++;
                        b[q.front()]=j;
                        q.pop();
                        break;
                    }
        }
    }
    printf("%d\n",sum);
    return 0;
}
