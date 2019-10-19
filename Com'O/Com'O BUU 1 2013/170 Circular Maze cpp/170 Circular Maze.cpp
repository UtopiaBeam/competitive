#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
typedef pair <int,int> ord;
queue <ord> q;
char a[110][110];
int b[110][110],r,c;
int main(){
    int i,j,now;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='S')
                q.push(ord(i,j));
        }
    b[(q.front()).first][(q.front()).second]=0;
    while(!q.empty()){
        i=(q.front()).first,j=(q.front()).second;
        if(i<0)     i=r-1;
        if(i>r-1)   i=0;
        if(j<0)     j=c-1;
        if(j>c-1)   j=0;
        now=b[i][j];
        if(i>0 && b[i-1][j]==-1 && a[i-1][j]!='#'){
            q.push(ord(i-1,j));     b[i-1][j]=now+1;
        }
        if(j>0 && b[i][j-1]==-1 && a[i][j-1]!='#'){
            q.push(ord(i,j-1));     b[i][j-1]=now+1;
        }
        if(i<r-1 && b[i+1][j]==-1 && a[i+1][j]!='#'){
            q.push(ord(i+1,j));     b[i+1][j]=now+1;
        }
        if(j<c-1 && b[i][j+1]==-1 && a[i][j+1]!='#'){
            q.push(ord(i,j+1));     b[i][j+1]=now+1;
        }
        q.pop();
    }
    printf("%d\n",now);
    return 0;
}
