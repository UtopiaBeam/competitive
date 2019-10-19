#include<cstdio>
int a,b,c,d,mn=1<<30,mx=-1<<30,chk[202][202][202];
void f(int x,int y,int z,int cnt){
    if(chk[x][y][z])    return ;
    chk[x][y][z]=1;
    if(x<=d){
        if(mx<x)    mx=x,mn=cnt;
        else if(mx==x && mn>cnt)    mn=cnt;
    }
    if(y<=d){
        if(mx<y)    mx=y,mn=cnt;
        else if(mx==y && mn>cnt)    mn=cnt;
    }
    if(z<=d){
        if(mx<z)    mx=z,mn=cnt;
        else if(mx==z && mn>cnt)    mn=cnt;
    }
    if(x){
        if(x+y<=b)  f(0,x+y,z,cnt+x);
        else    f(x-(b-y),b,z,cnt+b-y);
        if(x+z<=c)  f(0,y,x+z,cnt+x);
        else    f(x-(c-z),y,c,cnt+c-z);
    }
    if(y){
        if(y+x<=a)  f(x+y,0,z,cnt+y);
        else    f(a,y-(a-x),z,cnt+a-x);
        if(y+z<=c)  f(x,0,y+z,cnt+y);
        else    f(x,y-(c-z),c,cnt+c-z);
    }
    if(z){
        if(z+x<=a)  f(x+z,y,0,cnt+z);
        else    f(a,y,z-(a-x),cnt+a-x);
        if(z+y<=b)  f(x,z+y,0,cnt+z);
        else    f(x,b,z-(b-y),cnt+b-y);
    }
    chk[x][y][z]=0;
}
int main(){
    scanf("%d %d %d %d",&a,&b,&c,&d);
    f(0,0,c,0);
    printf("%d %d\n",mn,mx);
}
