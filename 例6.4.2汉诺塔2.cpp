#include<stdio.h>
#include<math.h>
long long f[65];
long long INF=99999999;
int main(){
	int n;
	f[1]=1;
	f[2]=3;
	for(int i=3;i<65;i++){
		int min=INF;
		for(int x=1;x<i;x++){
			if(2*f[x]+pow(2,i-x)-1<min){
				min=2*f[x]+pow(2,i-x)-1;
			}
		}
		f[i]=min;	
	}
	while(scanf("%d",&n)!=EOF){
		printf("%lld",f[n]);
	}
	
	
	return 0;
}
