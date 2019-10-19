#include<stdio.h>
int root[100010],h[100010];
int find(int i){
    if(root[i]!=i)
        root[i]=find(root[i]);
    return root[i];
}
int main(){
    int n,q,i,a,b,roota,rootb;
    char cmd;
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++){
        root[i]=i;
        h[i]=0;
    }
    while(q--){
        scanf(" %c %d %d",&cmd,&a,&b);
        roota=find(a);  rootb=find(b);
        if(cmd=='c'){
            if(h[roota]==h[rootb]){
                root[roota]=rootb;
                h[rootb]++;
            }
            else if(h[roota]>h[rootb])
                root[rootb]=roota;
            else
                root[roota]=rootb;
        }
        else if(cmd=='q'){
            if(roota==rootb)    printf("yes\n");
            else    printf("no\n");
        }
    }
    return 0;
}
