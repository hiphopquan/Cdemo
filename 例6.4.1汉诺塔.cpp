#include<stdio.h>
int cnt=0;
int han(int n,int from,int to,int helper){
	if(n==1){
		cnt++;
		printf("%d-->%d\n",from,to);
	}else{
		han(n-1,from,helper,to);
		cnt++;
		printf("%d-->%d\n",from,to);
		han(n-1,helper,to,from);
	}
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0){
		han(n,1,3,2);
	}
	return 0;
}
