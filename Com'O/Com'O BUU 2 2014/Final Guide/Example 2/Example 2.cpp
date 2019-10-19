/*
    1 2 3 4 5 6 7
  1 . . . . . . .
  2 . . . . . . M <- start      path M -> M = 'x'
  3 . . . . . . *               N -> S -> E -> W
  4 * * * * * . *               print path
  5 . . . . * . .
  6 . . . . * . .
  7 . M . . * . .
  8 . . . . . . .
*/
#include<cstdio>
#include<vector>
using namespace std;
pair <int,int> idx;
vector<pair <int ,int> > q;
int w,h,chk=1,b[110][110];
char a[110][110];
int main(){
    int i,j,state,nowi,nowj;
    scanf("%d %d",&w,&h);
    for(i=0;i<h;i++)
        for(j=0;j<w;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='M'&&chk){
                chk=0;  idx.first=i,idx.second=j;
                q.push_back(idx);
            }
        }
    while(!q.empty()){
        //
    }
}
