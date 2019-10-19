#include<cstdio>
int i=0,v=0,x=0,l=0,c=0,n;
int main(){
    scanf("%d",&n);
    for(int k=1;k<=n;k++){
        int t=k;
        if(t/100)   c+=t/100;
        t%=100;
        if(t/10){
            if(t/10==9)     c++,x++;
            else if(t/10>4) l++,x+=t/10-5;
            else if(t/10==4)    l++,x++;
            else    x+=t/10;
        }
        t%=10;
        if(t){
            if(t==9)    i++,x++;
            else if(t>4)    v++,i+=t-5;
            else if(t==4)   i++,v++;
            else    i+=t;
        }
    }
    printf("%d %d %d %d %d\n",i,v,x,l,c);
    return 0;
}
