#include<cstdio>
int a[500005],chk=1,str=1,n,m;
int get(int x){
    return (str+chk*(x-1)+n-1)%n+1;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    while(m--){
        char ch;
        int x,y,tx,ty,t;
        scanf(" %c %d",&ch,&x);
        if(ch=='a'){
            scanf("%d",&y);
            tx=get(x),ty=get(y);
            t=a[tx],a[tx]=a[ty],a[ty]=t;
        }
        else if(ch=='b'){
            scanf("%d",&y);
            tx=get(x);
            a[tx]=y;
        }
        else if(ch=='c'){
            str+=chk*(x-1);
            str=(str+n-1)%n+1;
            chk*=-1;
        }
        else if(ch=='q')   printf("%d\n",a[get(x)]);
    }
    return 0;
}
