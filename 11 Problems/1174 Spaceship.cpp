#include<cstdio>
using namespace std;
class{
public:
    int x,y,z,m,k,c;
    int f(int x,int y,int z){
        return (x-this->x)*(x-this->x)+(y-this->y)*(y-this->y)+(z-this->z)*(z-this->z);
    }
}a[20];
int n,q,xi,yi,zi,mark[20],min=1<<20;
void play(int x,int y,int z,int m,int k,int c,int cost){
    if(m>=n && k>=n && c>=n){
        if(min>cost)    min=cost;
        return ;
    }
    for(int i=0;i<q;i++){
        if(!mark[i]){
            mark[i]=1;
            play(a[i].x,a[i].y,a[i].z,m+a[i].m,k+a[i].k,c+a[i].c,cost+a[i].f(x,y,z));
            mark[i]=0;
        }
    }
}
int main(){
    scanf("%d %d %d %d %d",&n,&xi,&yi,&zi,&q);
    for(int i=0;i<q;i++)
        scanf("%d %d %d %d %d %d",&a[i].x,&a[i].y,&a[i].z,&a[i].m,&a[i].k,&a[i].c);
    play(xi,yi,zi,0,0,0,0);
    printf("%d\n",min);
    return 0;
}
