#include<cstdio>
#include<algorithm>
using namespace std;
int l[100002],r[100002],mx[100002],mn[100002];
int main(){
    int chk=0,cnt=0,n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&l[i],&r[i]);
        if(l[i]<0)  l[i]=0;
        if(r[i]<0)  r[i]=0;
    }
    for(int i=n;i>0;i--){
        if(mx[r[i]]>mn[l[i]])   cnt++;
        mn[i]=min(mn[l[i]],mn[r[i]])+1;
        mx[i]=max(mx[l[i]],mx[r[i]])+1;
        if(mx[i]-mn[i]>1 || (mx[l[i]]!=mn[l[i]] && mx[r[i]]!=mn[r[i]])){
            chk=1;      break;
        }
    }
    if(chk)     printf("-1\n");
    else        printf("%d\n",cnt);
    return 0;
}
