#include<cstdio>
int n,x=0,y=0,cnt=1,l=0;
char a[200002];
void f(int r){
    while(l<r){
        if(a[l]=='U')   y--;
        if(a[l]=='D')   y++;
        if(a[l]=='R')   x--;
        if(a[l]=='L')   x++;
        l++;
    }
    cnt++;
}
int main(){
    scanf("%d %s",&n,a);
    for(int r=0;r<n;r++){
        if(a[r]=='U'){
            if(y<0)     f(r);
            y++;
        }
        if(a[r]=='D'){
            if(y>0)     f(r);
            y--;
        }
        if(a[r]=='R'){
            if(x<0)     f(r);
            x++;
        }
        if(a[r]=='L'){
            if(x>0)     f(r);
            x--;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
