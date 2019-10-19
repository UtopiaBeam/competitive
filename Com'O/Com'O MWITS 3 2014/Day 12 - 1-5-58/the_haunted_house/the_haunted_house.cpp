#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
class pnt{
public:
    int x,y;
    char str[10];
}b[1000005];
char a[1005][1005];
int r,c,mark[1005][1005],n,cnt=1;
bool cmp(pnt x,pnt y){
    return strcmp(x.str,y.str)<0;
}
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)    a[i][0]=a[i][c-1]='#';
    for(int i=0;i<c;i++)    a[0][i]=a[r-1][i]='#';
    for(int i=0;i<r;i++)
        printf("%s\n",a[i]);
//    for(int i=0;i<r;i++)
//        scanf(" %s",a[i]);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d %s",&b[i].x,&b[i].y,b[i].str);
    sort(b,b+n,cmp);
    return 0;
}
