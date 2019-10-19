#include<cstdio>
int a;
long long b,s,e,mxs=0,mne=1e9;
int main(){
    scanf("%d %lld",&a,&b);
    while(a--){
        scanf("%lld %lld",&s,&e);
        if(s>e){
            if(mxs<s)   mxs=s;
            if(mne>e)   mne=e;
        }
    }
    if(mne==1e9)    mne=0;
    printf("%lld\n",b+2*(mxs-mne));
    return 0;
}
