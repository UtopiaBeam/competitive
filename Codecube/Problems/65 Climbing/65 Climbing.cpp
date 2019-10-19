#include<cstdio>
#include<algorithm>
int n,a,b,c;
void f(int &x,int &y,int &z){
    if(x<y && x<z)  x+=2*(std::min(y,z)-x);
    else if(x<y)    x+=2*(y-x);
    else if(x<z)    x+=2*(z-x);
}
int main(){
    scanf("%d %d %d %d",&n,&a,&b,&c);
    for(int i=0;i<n;i++){
        if(i%3==0)  f(a,b,c);
        else if(i%3==1) f(b,a,c);
        else    f(c,a,b);
    }
    printf("%d\n%d\n%d\n",a,b,c);
    return 0;
}
