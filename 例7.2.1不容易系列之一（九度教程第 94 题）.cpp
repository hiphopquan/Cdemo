#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int num[21];
		num[1]=0;
		num[2]=1; 
		for(int i=3;i<=n;i++){
			//num[i]=(i-1)*num[i-1];//错误未考虑被装入错误信的信封对应的新装入哪里
			num[i]=(i-1)*num[i-1]+(i-1)*num[i-2];
		}
		printf("%d\n",num[n]);
	}
	return 0;
} 
