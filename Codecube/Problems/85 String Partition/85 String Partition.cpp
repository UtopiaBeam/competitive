#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[100002];
int cnt[30],mn=(int)1e9;
int main(){
	scanf(" %s",a);
	int len=strlen(a),mn=1e9;
	for(int i=1;i<=len/2;i++){
		if(len%i==0){
            int t=0;
			for(int j=0;j<i;j++){
                int mx=0;
				memset(cnt,0,sizeof(cnt));
				for(int k=0;k<len;k+=i)    cnt[a[k+j]-'a']++;
                for(int k=0;k<26;k++)   mx=max(mx,cnt[k]);
                t+=len/i-mx;
			}
			mn=min(mn,t);
		}
	}
	printf("%d\n",mn);
	return 0;
}
