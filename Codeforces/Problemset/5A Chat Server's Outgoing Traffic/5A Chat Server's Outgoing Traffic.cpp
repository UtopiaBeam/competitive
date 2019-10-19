#include<cstdio>
#include<cstring>
int cnt=0,ans=0;
char a[105];
int main(){
    while(gets(a)!=NULL){
        if(a[0]=='+')   cnt++;
        else if(a[0]=='-')  cnt--;
        else{
            int len=strlen(a);
            for(int i=0;a[i];i++)
                if(a[i]==':'){
                    ans+=cnt*(len-i-1);
                    break;
                }
        }
    }
    printf("%d\n",ans);
    return 0;
}
