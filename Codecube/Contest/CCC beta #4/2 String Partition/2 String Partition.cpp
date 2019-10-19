#include<cstdio>
#include<cstring>
char a[100002];
int main(){
	scanf(" %s",a);
	int len=strlen(a),mn=1e9;
	for(int i=1;i<=len/2;i++){
		if(len%i==0){
			for(int k=0;k<len;k+=i){
				int cnt=0;
				for(int j=0;j<i;j++)
					cnt+=(a[k+j%i]!=a[j]);
				if(mn>cnt)  mn=cnt;
			}
		}
	}
	printf("%d\n",mn);
	return 0;
}
