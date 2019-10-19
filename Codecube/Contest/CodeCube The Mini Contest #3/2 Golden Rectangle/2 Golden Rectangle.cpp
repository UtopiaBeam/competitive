#include<cstdio>
#include<vector>
#include<algorithm>
#define S second
#define P pair<int,int>
#define PP pair<P,int>
using namespace std;
int b[20]={1,1},n,x=0,y=0,r=0,c=1;
vector<PP> a;
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
        b[i]=b[i-1]+b[i-2];
    for(int i=0;i<n;i++){
        if(i%2)     c+=b[i];
        else        r+=b[i];
        for(int j=0;j<b[i];j++)
            for(int k=0;k<b[i];k++)
                a.push_back(PP(P(x+j,y+k),'A'+i));
        switch(i%4){
            case 0:
                y+=b[i];
                break;
            case 1:
                x+=b[i],y-=b[i-1];
                break;
            case 2:
                x-=b[i-1],y-=b[i+1];
                break;
            default:
                x-=b[i+1];
        }
    }
    sort(a.begin(),a.end());
    int in=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            printf("%c",a[in++].S);
        printf("\n");
    }
    return 0;
}
