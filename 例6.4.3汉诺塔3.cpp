#include<stdio.h>
int cnt=0;
void han(int n,int from,int to,int helper){
	if(n==1){
		cnt++;
//		printf("%d-->%d\n",from,helper);
		cnt++;
//		printf("%d-->%d\n",helper,to);
	}else{
		han(n-1,from,to,helper);
		cnt++;
//		printf("%d-->%d\n",from,helper);
		han(n-1,to,from,helper);
		cnt++;
//		printf("%d-->%d\n",helper,to);
		han(n-1,from,to,helper); 
	}
}
int funhan(int n){
	if(n==1){
		return 2;
	}else{
		return 3*funhan(n-1)+2;
	}
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		//han(n,1,3,2);
		//printf("%d",cnt);
		cnt=funhan(n);
		printf("%d",cnt);
	}
	return 0;
} 
