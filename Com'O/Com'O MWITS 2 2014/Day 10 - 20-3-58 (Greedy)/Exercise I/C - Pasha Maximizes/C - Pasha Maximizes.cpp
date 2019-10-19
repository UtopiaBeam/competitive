#include<cstdio>
#include<cstring>
char a[20];
int main(){
    scanf(" %s",a);
    int len=strlen(a),k,t;
    scanf("%d",&k);
    if(len==1){
        printf("%s\n",a);
        return 0;
    }
    for(int i=0;i<len;i++)
        a[i]-='0';
    for(int i=0;i<len;i++){
        int max=i;
        for(int j=i+1;j<=i+k && j<len;j++)
            if(a[max]<a[j])    max=j;
        if(max!=i){
            for(int j=max;j>i;j--)
                t=a[j],a[j]=a[j-1],a[j-1]=t;
            k-=max-i;
        }
    }
    for(int i=0;i<len;i++)
        printf("%d",a[i]);
    printf("\n");
    return 0;
}
