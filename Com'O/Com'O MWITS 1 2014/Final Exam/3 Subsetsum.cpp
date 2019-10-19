#include<stdio.h>
#include<math.h>
int a[25],b[25],n,t;
void play(int i){
	int in=0;
	while(i){
		b[in++]=i%2;
		i/=2;
	}
}
int main(){
	scanf("%d %d",&n,&t);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=(int)pow(2,n);i++){
		int sum=0,cnt=0;
		play(i);
		for(int j=0;j<n;j++)
			if(b[j])	sum+=a[j]*b[j],cnt++;
		if(sum==t){
			printf("%d\n",cnt);
			for(int j=0;j<n;j++)
				if(b[j])	printf("%d ",j+1);
			printf("\n");
			return 0;
		}
	}
	printf("0\n");
	return 0;
}
